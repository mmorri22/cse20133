#include <cmath>
#include <matplot/matplot.h>

using namespace matplot;

int main() {
    
    std::vector<double> t = iota(0, pi / 50, 10 * pi);
    std::vector<double> st = transform(t, [](auto x) { return sin(x); });
    std::vector<double> ct = transform(t, [](auto x) { return cos(x); });

    /*
    std::vector<double> st;
    std::vector<double> ct;
    for( size_t iter = 0; iter < t.size(); ++iter){

        st.push_back( sin(t.at(iter)) );
        ct.push_back( cos(t.at(iter)) );
    }
    
    */
    auto l = plot3(st, ct, t);

    title("Inital 3D Plot Example");
    show();
    return 0;
}
