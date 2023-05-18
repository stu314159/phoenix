#include "DarcyPressure.h"

registerMooseObject("PhoenixApp",DarcyPressure);

InputParameters
DarcyPressure::validParams()
{
    auto params = ADKernelGrad::validParams();
    params.addClassDescription("Same 'Diffusion' in terms of physics/residual, but the Jacobian "
    "is computed using forward automatic differentiation");
    return params;
}

DarcyPressure::DarcyPressure(const InputParameters & parameters) : 
ADKernelGrad(parameters),
_permeability(0.8451e-09),
_viscosity(7.98e-04)
{

}

ADRealVectorValue
DarcyPressure::precomputeQpResidual()
{
    return (_permeability/_viscosity)*_grad_u[_qp]; //note _grad_test[_qp] is automatically applied.
}