/**
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUMWINDOWS_MEDIA_AUDIOPLAYER_HPP_
#define _TITANIUMWINDOWS_MEDIA_AUDIOPLAYER_HPP_

#include "TitaniumWindows_Media_EXPORT.h"
#include "Titanium/Media/AudioPlayer.hpp"

namespace TitaniumWindows
{
	using namespace HAL;

	namespace Media
	{
		/*!
	      @class AudioPlayer
	      @ingroup Titanium.Media.AudioPlayer

	      @discussion This is the Titanium.Media.AudioPlayer implementation for Windows.
	    */
		class TITANIUMWINDOWS_MEDIA_EXPORT AudioPlayer final : public Titanium::Media::AudioPlayer, public JSExport<AudioPlayer>
		{
		public:

			TITANIUM_FUNCTION_UNIMPLEMENTED(stateDescription);
			TITANIUM_FUNCTION_UNIMPLEMENTED(release);
			TITANIUM_PROPERTY_UNIMPLEMENTED(allowBackground);

			virtual void set_paused(const bool& paused) TITANIUM_NOEXCEPT override;
			virtual void set_url(const std::string& url) TITANIUM_NOEXCEPT override;
			virtual void set_volume(const double& volume) TITANIUM_NOEXCEPT override;
			virtual std::chrono::milliseconds get_time() const TITANIUM_NOEXCEPT override;

			virtual void pause() TITANIUM_NOEXCEPT override;
			virtual void play() TITANIUM_NOEXCEPT override;
			virtual void start() TITANIUM_NOEXCEPT override;
			virtual void stop() TITANIUM_NOEXCEPT override;

			AudioPlayer(const JSContext&) TITANIUM_NOEXCEPT;

			virtual ~AudioPlayer();
			AudioPlayer(const AudioPlayer&) = default;
			AudioPlayer& operator=(const AudioPlayer&) = default;
	#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			AudioPlayer(AudioPlayer&&) = default;
			AudioPlayer& operator=(AudioPlayer&&) = default;
	#endif

			static void JSExportInitialize();
			virtual void postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments) override;

			virtual void enableEvent(const std::string& event_name) TITANIUM_NOEXCEPT override final;
			virtual void disableEvent(const std::string& event_name) TITANIUM_NOEXCEPT override final;

		protected:
			Windows::UI::Xaml::Controls::MediaElement ^ player__;
			Windows::Foundation::EventRegistrationToken complete_event__;
			Windows::Foundation::EventRegistrationToken failed_event__;
			Windows::Foundation::EventRegistrationToken navigated_event__;
		};

	} // namespace Media
} // namespace TitaniumWindows

#endif  // _TITANIUMWINDOWS_MEDIA_AUDIOPLAYER_HPP_
