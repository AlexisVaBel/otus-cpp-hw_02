mkdir ./build
cd ./build
CXX=clang++ CC=clang cmake ..
make -j4
echo "starting tests"
./ip_filter_test
