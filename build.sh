./prepare.sh
rm -rf build
mkdir build
make
cp SDL/build/build/.libs/libSDL2-2.0.0.dylib build/libSDL2-2.0.0.dylib
install_name_tool -change /usr/local/lib/libSDL2-2.0.0.dylib @executable_path/libSDL2-2.0.0.dylib build/chip