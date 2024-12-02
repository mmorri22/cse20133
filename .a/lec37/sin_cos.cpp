#include <cmath>
#include <matplot/matplot.h>

using namespace matplot;

#define NUM_POINTS 50

int main() {

    std::vector<double> x_vals = linspace( -2*M_PI, 2*M_PI, NUM_POINTS );

    std::vector<double> sin_vals;
    std::vector<double> cos_vals;

    for( size_t iter = 0; iter < NUM_POINTS; ++iter ){

        double curr_x = x_vals.at(iter);
        sin_vals.push_back( sin(curr_x) );
        cos_vals.push_back( cos(curr_x) );
    }

    auto the_plots = plot( x_vals, sin_vals, x_vals, cos_vals );

    the_plots.at(0)->line_width(2);

    the_plots.at(0)->marker(line_spec::marker_style::square).marker_face_color("#0c23d0");
    the_plots.at(1)->marker(line_spec::marker_style::circle).marker_face_color("#C99700");

    title("Sin/Cos Comparison");
    xlabel("x");
    ylabel("y");

    legend({"sin(x)", "cos(x)"});
    show();

    return 0;
}