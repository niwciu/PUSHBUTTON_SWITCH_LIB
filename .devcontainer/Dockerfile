#############################################################################################################
# To build container:
#       docker build -t USER_NAME/CONTAINER_NAME:VERSION_NUMB -t USER_NAME/CONTAINER_NAME:latest .
#   example:
#       docker build -t niwciu/stm32_dev_container:1.0.0 -t niwciu/stm32_dev_container:latest .
# To push the container:
#       docker push USER_NAME/CONTAINER_NAME:VERSION_NUMB  
#       docker push USER_NAME/CONTAINER_NAME:latest
#   example:
#       docker push niwciu/stm32_dev_container:latest
#       docker push niwciu/stm32_dev_container:1.0.0
#
############################################################################################################
FROM ubuntu:latest

# packages
RUN apt-get update && apt-get install -y --no-install-recommends \
    ca-certificates \
    cmake \
    g++ \ 
    git \
    ninja-build \
    wget \
    xz-utils \
    python3 \
    python3-venv \
    pip \
    pipx \
    make \
    clang-format \
    stlink-tools

# Set working directory and switch to the new user
WORKDIR /home/workspace

#inlstall lizard & gcovr 
# Install lizard & gcovr in the global directory
RUN pipx install lizard && pipx install gcovr && pipx ensurepath && pipx runpip lizard install jinja2

# tools directory
ARG TOOLS_DIRECTORY=/home/opt
RUN mkdir -p ${TOOLS_DIRECTORY}

# arm toolchain
ARG ARM_TOOLCHAIN_VERSION=13.2
ARG ARM_TOOLCHAIN_FILE=arm-gnu-toolchain-${ARM_TOOLCHAIN_VERSION}.rel1-x86_64-arm-none-eabi.tar.xz
ARG ARM_TOOLCHAIN_DIRECTORY=arm-gnu-toolchain-${ARM_TOOLCHAIN_VERSION}.Rel1-x86_64-arm-none-eabi

RUN wget -q https://developer.arm.com/-/media/Files/downloads/gnu/${ARM_TOOLCHAIN_VERSION}.rel1/binrel/${ARM_TOOLCHAIN_FILE} \
    && tar xf ${ARM_TOOLCHAIN_FILE} -C ${TOOLS_DIRECTORY} \
    && rm ${ARM_TOOLCHAIN_FILE}
ENV PATH=${PATH}:${TOOLS_DIRECTORY}/${ARM_TOOLCHAIN_DIRECTORY}/bin

# avr toolchain

# cppcheck
ARG CPPCHECK_VERSION=2.16.2
RUN cd ${TOOLS_DIRECTORY} && git clone https://github.com/danmar/cppcheck.git && cd cppcheck && git checkout ${CPPCHECK_VERSION} \
    && cmake -S . -B build -DCMAKE_BUILD_TYPE=Release -DUSE_MATCHCOMPILER=ON -G Ninja \
    && cmake --build build && cmake --install build \
    && cd .. && rm -rf cppcheck

RUN apt-get remove pipx -y
RUN apt autoremove -y
RUN rm -rf /var/lib/apt/lists/*
