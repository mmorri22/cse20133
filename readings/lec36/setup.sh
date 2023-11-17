sudo apt-get update
sudo apt install -y build-essential pkg-config
sudo apt upgrade cmake gnuplot libglfw3-dev
git clone http://github.com/alandefreitas/matplotplusplus
cd matplotplusplus/
mkdir compil-release
cd compil-release
sudo cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -DBUILD_SHARED_LIBS=ON -DBUILD_EXAMPLES=OFF -DBUILD_TESTS=OFF -DCMAKE_INSTALL_PREFIX="/usr/local/include/matplot1.0.1"
sudo make -j4
sudo make install
sudo cp source/matplot/libmatplot.dll /usr/local/include/matplot1.0.1/lib/libmatplot.dll