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
            std::unique_ptr<RT64::Application> app;
        };

        // ultramodern::renderer::callbacks_t::create_render_context_t implementation.
        std::unique_ptr<ultramodern::renderer::RendererContext> create_render_context(uint8_t* rdram, ultramodern::renderer::WindowHandle window_handle, bool developer_mode);
    }
}
