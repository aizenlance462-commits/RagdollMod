# Ginagamit ang static C++ library para hindi mag-error sa phone
APP_STL := c++_static

# Binibigyang kakayahan ang code na gumamit ng RTTI at Exceptions kung kailangan
APP_CPPFLAGS := -frtti -fexceptions

# Target architectures: Para gumana sa halos lahat ng Android phones
APP_ABI := arm64-v8a armeabi-v7a

# Minimum Android version (Android 5.0 Lollipop pataas)
APP_PLATFORM := android-21

# Optimization level
APP_OPTIM := release
