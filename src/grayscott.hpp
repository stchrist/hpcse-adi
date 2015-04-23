#ifndef GRAYSCOTT_HPP
#define GRAYSCOTT_HPP


#include <vector>

#include "tridiagmatrix.hpp"


class GrayScott
{
public:
    /**
     * Construct a new simulation object.
     * 
     * @param N         number of grid cells in one dimension
     * @param L         length of the domain in one dimension
     * @param dt        time step
     * @param Du        diffusion coefficient for u
     * @param Dv        diffusion coefficient for v
     * @param F         model parameter
     * @param k         model parameter
     * @param nSteps    number of steps in the simulation
     */
    GrayScott(int N, double L, double dt, double Du, double Dv, double F, double k, int nSteps);
    
    /**
     * Run the simulation.
     */
    void run();
    

    
private:
    
    /**
     * Perform one simulation step.
     */
    void step();



    ///////////////////////////// PARAMETERS ///////////////////////////////////
    /**
     * Grid size.
     * 
     * Number of cells in each direction. The grid is square.
     */
    const int N_;
    /**
     * Total number of grid cells.
     */
    int Ntot_;
    
    /**
     * Size of the domain.
     * 
     * Length of the computation domain in each direction. The grid is square.
     */
//    const double L_;
    
    const double dx_;
    
    /**
     * Time step.
     */
    const double dt_;
    
    
    /**
     * Number of simulation steps
     */
    const int nSteps_;
    /**
     * Current simulation step
     */
    int currStep_;
    
        
        
    ///////////////////////////// FIELDS ///////////////////////////////////////
    /**
     * Quantities to diffuse.
     * 
     * The quantities are two different chemical species.
     */
    std::vector<double> u_;
    std::vector<double> v_;
    
    /**
     * GrayScott coefficients.
     */
    const double Du_;
    const double Dv_;
    /**
     * Model parameters.
     */
    const double F_;
    const double k_;
    
        
    /**
     * @defgroup matrices   Tridiagonal matrices.
     * 
     * These matrices don't depend on the time step or the diffusing quantities and are thus constant.
     * 
     * @{
     */
     
    TriDiagMatrix matU1_; /**< Matrix for the first step of u. */
    TriDiagMatrix matU2_; /**< Matrix for the second step of u. */
    
    TriDiagMatrix matV1_;
    TriDiagMatrix matV2_;
    
    /** @} */
    
    
    /////////////////////// HELPER FUNCTIONS ///////////////////////////////////
    /**
     * Initialize the fields.
     * 
     * Initialize the chemical quantities U and V for the simulation.
     */
    void initialize_fields();
    
    /**
     * Print the fields to the specified file.
     * 
     * @param uName     filename of the file to print u to
     * @param vName     filename of the file to print v to
     */
    void print_fields();
    
    /**
     * Directory to save the output to
     */
    std::string dirPath_;
};



#endif

