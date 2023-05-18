#include "ADDiffusion.h"

registerMooseObject("PhoenixApp",ADDiffusion);

InputParameters
ADDiffusion::validParams()
{
    auto params = ADKernelGrad::validParams();
    params.addClassDescription("Same 'Diffusion' in terms of physics/residual, but the Jacobian "
    "is computed using forward automatic differentiation");
    return params;
}

ADDiffusion::ADDiffusion(const InputParameters & parameters) : 
ADKernelGrad(parameters)
{

}

ADRealVectorValue
ADDiffusion::precomputeQpResidual()
{
    return _grad_u[_qp]; //note _grad_test[_qp] is automatically applied.
}