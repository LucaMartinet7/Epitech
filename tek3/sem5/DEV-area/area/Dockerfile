FROM ubuntu:18.04

# Prerequisites
RUN apt update && apt install -y curl git unzip xz-utils zip libglu1-mesa openjdk-8-jdk wget

# Set up new user
RUN useradd -ms /bin/bash developer
USER developer
WORKDIR /home/developer

# Prepare Android directories and system variables
RUN mkdir -p Android/sdk
ENV ANDROID_SDK_ROOT=/home/developer/Android/sdk
RUN mkdir -p .android && touch .android/repositories.cfg

# Set up Android SDK
RUN wget -O sdk-tools.zip https://dl.google.com/android/repository/commandlinetools-linux-8512546_latest.zip
RUN unzip sdk-tools.zip -d Android/sdk/cmdline-tools
RUN mkdir -p Android/sdk/cmdline-tools/latest
RUN mv Android/sdk/cmdline-tools/cmdline-tools/* Android/sdk/cmdline-tools/latest/
RUN rm -rf Android/sdk/cmdline-tools/cmdline-tools
RUN rm sdk-tools.zip

# Accept licenses and install packages
RUN yes | Android/sdk/cmdline-tools/latest/bin/sdkmanager --licenses
RUN Android/sdk/cmdline-tools/latest/bin/sdkmanager "build-tools;29.0.2" "platform-tools" "platforms;android-29" "sources;android-29"

# Set PATH for Android SDK tools
ENV PATH="$PATH:/home/developer/Android/sdk/platform-tools"

# Download Flutter SDK
RUN git clone https://github.com/flutter/flutter.git
ENV PATH="$PATH:/home/developer/flutter/bin"

# Run basic check to download Dart SDK
RUN flutter doctor
