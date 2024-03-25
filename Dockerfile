FROM ubuntu:jammy

RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends \
    cmake \
    g++ \
    gcc \
    make \
    doxygen \
    qmake6 \
    qt6-base-dev \
    qt6-base-dev-tools \
    qt6-multimedia-dev \
    qt6-documentation-tools \
    qt6-declarative-dev \
    qt6-declarative-dev-tools \
    qt6-image-formats-plugins \
    qt6-l10n-tools \
    qt6-translations-l10n \
    libx11-xcb1 \
    libxcb1 \
    libxkbcommon-x11-0 \
    libxkbcommon0 \
    libxcb-keysyms1 \
    libxcb-image0 \
    libxcb-shm0 \
    libxcb-icccm4 \
    libxcb-sync1 \
    libxcb-xfixes0 \
    libxcb-shape0 \
    libxcb-randr0 \
    libxcb-render-util0 \
    xvfb \
    mlocate \
    libgl1-mesa-dev \
    qbs \
    gcovr \
    lcov \
    openjdk-17-jre \
    python3 \
    python3-pip \
    curl \
    unzip \
    && rm -rf /var/lib/apt/lists/*
RUN pip3 install "coverxygen==1.7.0"

RUN qtchooser -install 6 /usr/bin/qmake6 && qtchooser -install -f default /usr/bin/qmake6
RUN qbs setup-toolchains --detect && qbs setup-qt /usr/bin/qmake6 qt-6-2-4-bin && qbs config defaultProfile qt-6-2-4-bin


# Set the working directory in the container to /app
WORKDIR /app
COPY Pacman /app/Pacman

# Add the current directory contents into the container at /app
ADD . /app

# Build the project
RUN qmake /app/Pacman/Pacman.pro

RUN make

# Run the application
#CMD ["./PacmanApp"]
#ENTRYPOINT [ "/app/Pacman/Pacman" ]
