#ifdef ENGINE_TARGET_WIN32
#pragma once

#include <api.hpp>
#include <windows/base_app_window.hpp>

#include <Windows.h>

namespace engine::windows {
	struct ENGINE_API Win32AppWindow : public BaseAppWindow {
		bool init() override;
		void destroy() override;

		void set_title(std::string_view title) override;
		void set_position(utils::IVector2 position) override;
		void set_size(utils::IVector2 size) override;

		utils::IVector2 get_size() override;
		utils::IVector2 get_position() override;

		void process_events() override;
		void update() override;

		void show() override;
		void hide() override;

        bool is_focused() override;
	private:
		HWND window_handle{};

		void assert_window_init();

		LRESULT CALLBACK window_processor(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
		static LRESULT CALLBACK window_processor_static(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
        static utils::enums::input::KeyType map_key_type(uintptr_t wParam);
		static bool engine_window_class_exists();

		static constexpr const char* default_win_class_name{ "SPECTRAL_WINCLASS" };
		static constexpr const char* default_win_title{ "SpectralRift Engine" };
	};
}
#endif