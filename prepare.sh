echo "Preparing SDL2"
SDL_DIR="SDL"
if [ -d "$SDL_DIR" ]; then
    echo "SDL directory already exists. Please remove it if you want to reset it"
else
    git clone https://github.com/libsdl-org/SDL.git
    cd SDL
    mkdir build
    CC="${pwd}/build-scripts/clang-fat.sh"
    cd build
    ../configure
    make
fi
echo "Done preparing SDL2"