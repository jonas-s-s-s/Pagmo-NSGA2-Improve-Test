#pragma once
#include "pagmo/algorithm.hpp"
#include "pagmo/problem.hpp"

namespace nsga2Test
{
    inline constexpr int GEN_COUNT = 3500;
    inline constexpr int POPULATION_SIZE = 100;

    /*
     * Utility function which runs an algorithm on some problem for GEN_COUNT generations with POPULATION_SIZE
     */
    void run_algorithm_on_problem(const pagmo::problem& problem, const pagmo::algorithm& algorithm);

    /*
     * Functions to run different problem sets on our algorithm
     */
    void run_cec2014(const pagmo::algorithm& algorithm);
    void run_cec2013(const pagmo::algorithm& algorithm);
    void run_cec2009(const pagmo::algorithm& algorithm);
    void run_cec2006(const pagmo::algorithm& algorithm);
    void run_schwefel(const pagmo::algorithm& algorithm);
    void run_dtlz(const pagmo::algorithm& algorithm);
    void run_wfg(const pagmo::algorithm& algorithm);
    void run_zdt(const pagmo::algorithm& algorithm);

    /*
     * Non-dominated Sorting GA (NSGA2) pagmo::nsga2 M-U-I
     */
    void run_nsga2(const std::function<void(const pagmo::algorithm&)>& problemRunner);
}
