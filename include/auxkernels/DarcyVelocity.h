#pragma once

#include "AuxKernel.h"

class DarcyVelocity : public VectorAuxKernel
{
public: 
static InputParameters validParams();
DarcyVelocity(const InputParameters & parameters);

protected:

virtual RealVectorValue computeValue() override;
const VariableGradient & _grad_p;

const ADMaterialProperty<Real> & _permeability;
const ADMaterialProperty<Real> & _viscosity;
 
};