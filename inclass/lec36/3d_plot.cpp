#include <cmath>
#include <matplot/matplot.h>

using namespace matplot;

int main() {
    
    std::vector<double> t = iota(0, pi / 50, 10 * pi);
    std::vector<double> st = transform(t, [](auto x) { return sin(x); });
    std::vector<double> ct = transform(t, [](auto x) { return cos(x); });
    auto l = plot3(st, ct, t);

    title("Inital 3D Plot Example");
    show();
    return 0;
}
