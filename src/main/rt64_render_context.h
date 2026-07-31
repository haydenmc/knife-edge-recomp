#pragma once

// RT64 renderer wiring for Knife Edge Recompiled.
//
// Adapted from Zelda64Recomp's src/main/rt64_render_context.{h,cpp} (see
// analysis/docs/build-notes.md for what changed): this keeps the core
// RT64::Application setup/config-mapping/frame-submission logic but drops
// everything tied to Zelda64Recomp's own UI layer and texture-pack/mod
// system (recompui::set_render_hooks(), ReplacementDirectory handling,
// enable/disable_texture_pack), none of which exist in this project yet.

#include <cstdint>
#include <memory>

#include "ultramodern/renderer_context.hpp"

namespace RT64 {
    struct Application;
}

namespace kerecomp {
    namespace renderer {
        class RT64Context final : public ultramodern::renderer::RendererContext {
        public:
            ~RT64Context() override;
            RT64Context(uint8_t* rdram, ultramodern::renderer::WindowHandle window_handle, bool developer_mode);

            bool valid() override { return static_cast<bool>(app); }

            bool update_config(const ultramodern::renderer::GraphicsConfig& old_config, const ultramodern::renderer::GraphicsConfig& new_config) override;

            void enable_instant_present() override;
            void send_dl(const OSTask* task) override;
            void update_screen() override;
            void shutdown() override;
            uint32_t get_display_framerate() const override;
            float get_resolution_scale() const override;

        private:
            // Extended-GBI display-list prologue, shared by the
            // high_framerate (analysis/docs/high-framerate.md) and
            // hud_relocation (analysis/docs/hud-relocation.md)
            // enhancements: returns game_dl_addr unchanged unless one of
            // them is active, in which case it writes a short prologue to
            // scratch RDRAM and returns its address instead. Implemented in
            // rt64_render_context.cpp.
            // `hud_active` says whether this frame actually contains
            // relocated HUD, which decides both whether the extended
            // opcode has to stay registered across the game's own display
            // list and whether the scissor re-expression is needed.
            uint32_t maybe_inject_prologue(uint32_t game_dl_addr, bool hud_active);

            // hud_relocation enhancement: repoints this frame's HUD
            // display-list calls at re-anchoring stubs in scratch RDRAM,
            // returning how many it repointed. No-op (0) unless the
            // enhancement is on.
            uint32_t maybe_redirect_hud(uint32_t game_dl_addr);
            bool hud_relocation_active();

            // One-time "is the scratch RDRAM region still all zeroes"
            // check shared by both of the above; false means neither
            // writes anything, ever.
            bool scratch_usable();

            std::unique_ptr<RT64::Application> app;
        };

        // Turns the hud_relocation enhancement on/off (re-anchors the
        // in-mission HUD to the true window edges instead of the centered
        // 4:3 column). `vertical_shift` is the full_height correction: with
        // the letterbox removed the bottom clusters must move 20 px down to
        // reach the newly-exposed frame edge; with the letterbox still there
        // they are already flush against it.
        // Call once, before recomp::start(), with the resolved
        // kerecomp::EnhancementFlags's values.
        void set_hud_relocation_enhancement(bool on, bool vertical_shift);

        // ultramodern::renderer::callbacks_t::create_render_context_t implementation.
        std::unique_ptr<ultramodern::renderer::RendererContext> create_render_context(uint8_t* rdram, ultramodern::renderer::WindowHandle window_handle, bool developer_mode);
    }
}
