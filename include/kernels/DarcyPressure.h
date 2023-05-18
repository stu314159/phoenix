#pragma once

// Including the ADKernel base class here so we can extend it
#include "ADKernelGrad.h"

class ADDiffusion : public ADKernelGrad
{
    public:
    static InputParameters validParams();
    ADDiffusion(const InputParameters & parameters);

    protected:
    virtual ADRealVectorValue precomputeQPResidual() override;
    
};