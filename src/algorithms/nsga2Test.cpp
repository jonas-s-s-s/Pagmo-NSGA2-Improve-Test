#include "nsga2Test.h"

#include "pagmo/algorithms/pso.hpp"
#include "pagmo/algorithm.hpp"
#include "pagmo/archipelago.hpp"
#include "pagmo/problem.hpp"
#include "pagmo/algorithms/nsga2.hpp"
#include "pagmo/algorithms/xnes.hpp"
#include "pagmo/problems/cec2006.hpp"
#include "pagmo/problems/cec2009.hpp"
#include "pagmo/problems/cec2013.hpp"
#include "pagmo/problems/cec2014.hpp"
#include "pagmo/problems/dtlz.hpp"
#include "pagmo/problems/schwefel.hpp"
#include "pagmo/problems/wfg.hpp"
#include "pagmo/problems/zdt.hpp"
#include "pagmo/utils/multi_objective.hpp"

void nsga2Test::run_algorithm_on_problem(const pagmo::problem& problem, const pagmo::algorithm& algorithm)
{
    pagmo::population pop{problem, POPULATION_SIZE};

    // Evolve the population
    pop = algorithm.evolve(pop);

    // Output the population
    std::cout << "Best 5 individual: \n";
    const auto pop_decision_vectors = pop.get_x();
    const auto sorted_indexes = pagmo::sort_population_mo(pop_decision_vectors);
    for (int i = 0; i < 5 && i < sorted_indexes.size(); ++i)
    {
        const auto individual = pop_decision_vectors.at(sorted_indexes.at(i));
        std::cout << "[ ";
        for (const double val : individual)
        {
            std::cout << val << ", ";
        }
        std::cout << "]" << std::endl;
    }
}


void nsga2Test::run_cec2014(const pagmo::algorithm& algorithm)
{
    std::cout << std::endl << "Running CEC2014 for algorithm: " << algorithm.get_name() << std::endl;

    // This runs each of the CEC2014 problems for this algorithm
    for (int i = 1; i <= 30; ++i)
    {
        //std::cout << "-------------------------------------------------------" << std::endl;
        //std::cout << "CEC2014 problem No." << i << std::endl;
        const pagmo::problem prob{pagmo::cec2014(i, 30)};
        run_algorithm_on_problem(prob, algorithm);
    }
}

void nsga2Test::run_cec2013(const pagmo::algorithm& algorithm)
{
    std::cout << std::endl << "Running CEC2013 for algorithm: " << algorithm.get_name() << std::endl;

    for (int i = 1; i <= 28; ++i)
    {
        //std::cout << "-------------------------------------------------------" << std::endl;
        //std::cout << "CEC2013 problem No." << i << std::endl;
        const pagmo::problem prob{pagmo::cec2013(i, 30)};
        run_algorithm_on_problem(prob, algorithm);
    }
}

void nsga2Test::run_cec2009(const pagmo::algorithm& algorithm)
{
    std::cout << std::endl << "Running CEC2009 for algorithm: " << algorithm.get_name() << std::endl;

    for (int i = 1; i <= 20; ++i)
    {
        //std::cout << "-------------------------------------------------------" << std::endl;
        //std::cout << "CEC2009 problem No." << i << std::endl;
        const pagmo::problem prob{pagmo::cec2009(i, false, 30)};
        run_algorithm_on_problem(prob, algorithm);
    }
}

void nsga2Test::run_cec2006(const pagmo::algorithm& algorithm)
{
    std::cout << std::endl << "Running CEC2006 for algorithm: " << algorithm.get_name() << std::endl;

    for (int i = 1; i <= 24; ++i)
    {
        //std::cout << "-------------------------------------------------------" << std::endl;
        //std::cout << "CEC2006 problem No." << i << std::endl;
        const pagmo::problem prob{pagmo::cec2006(i)};
        run_algorithm_on_problem(prob, algorithm);
    }
}

void nsga2Test::run_schwefel(const pagmo::algorithm& algorithm)
{
    std::cout << std::endl << "Running schwefel function for algorithm: " << algorithm.get_name() << std::endl;
    pagmo::problem prob{pagmo::schwefel(30)};
    run_algorithm_on_problem(prob, algorithm);
}

void nsga2Test::run_dtlz(const pagmo::algorithm& algorithm)
{
    std::cout << std::endl << "Running DTLZ for algorithm: " << algorithm.get_name() << std::endl;
    std::cout << "==================================================================" << std::endl << std::endl;

    for (int i = 1; i <= 7; ++i)
    {
        //std::cout << "-------------------------------------------------------" << std::endl;
        //std::cout << "DTLZ problem No." << i << std::endl;
        const pagmo::problem prob{pagmo::dtlz(i)};
        run_algorithm_on_problem(prob, algorithm);
    }
}

void nsga2Test::run_wfg(const pagmo::algorithm& algorithm)
{
    std::cout << std::endl << "Running WFG for algorithm: " << algorithm.get_name() << std::endl;
    std::cout << "==================================================================" << std::endl << std::endl;

    for (int i = 1; i <= 9; ++i)
    {
        //std::cout << "-------------------------------------------------------" << std::endl;
        //std::cout << "WFG problem No." << i << std::endl;
        const pagmo::problem prob{pagmo::wfg(i)};
        run_algorithm_on_problem(prob, algorithm);
    }
}

void nsga2Test::run_zdt(const pagmo::algorithm& algorithm)
{
    std::cout << std::endl << "Running ZDT for algorithm: " << algorithm.get_name() << std::endl;
    std::cout << "==================================================================" << std::endl << std::endl;
    for (int i = 1; i <= 6; ++i)
    {
        //std::cout << "-------------------------------------------------------" << std::endl;
        //std::cout << "ZDT problem No." << i << std::endl;
        const pagmo::problem prob{pagmo::zdt(i)};
        run_algorithm_on_problem(prob, algorithm);
    }
}


void nsga2Test::run_nsga2(const std::function<void(const pagmo::algorithm&)>& problemRunner)
{
    pagmo::algorithm nsga2{pagmo::nsga2(GEN_COUNT)};
    nsga2.set_verbosity(0);
    problemRunner(nsga2);
}
