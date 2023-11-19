#include <matplot/matplot.h>
#include <random>

int main() {
    using namespace matplot;

    std::vector<double> theta = linspace(0, 1, 500);

    std::vector<double> x_coor;
    std::vector<double> y_coor;

    for( size_t iter = 0; iter < theta.size(); ++iter ){

        double temp_theta = theta.at(iter);
        x_coor.push_back( 0.25 * exp(temp_theta) * sin(50 * temp_theta) );
        y_coor.push_back( 0.25 * exp(temp_theta) * cos(50 * temp_theta) );
    }

    // auto s = scatter(x_coor, y_coor);

    auto s = scatter3(x_coor, y_coor, theta);

    s->marker_color("b");
    s->marker_face_color({0, .5, .5});

    show();
    return 0;
}