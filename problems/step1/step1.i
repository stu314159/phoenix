[Mesh]
    [gmg]
        type = GeneratedMeshGenerator 
        dim = 2
        nx = 100
        ny = 10
        xmax = 0.304
        ymax = 0.0257
    []
    coord_type = RZ
    rz_coord_axis = X

[]

[Variables]
    [pressure]
        family = LAGRANGE
        order = FIRST
          
    []
[]

[Kernels]
    [diffusion]
        type = ADDiffusion
        variable = pressure
        
    []
[]

[BCs]
    [left]
        #type = ADDirichletBC
        type = DirichletBC
        variable = pressure
        boundary = left
        value = 4000 

    []
    [right]
        #type = ADDirichletBC
        type = DirichletBC
        variable = pressure
        boundary = right
        value = 0

    []
[]

[Problem]
    type = FEProblem
[]

[Executioner]
    type = Steady
    solve_type = LINEAR
    #petsc_options_iname = '-pc_type -pc_hypre_type'
    #petsc_options_value = 'hypre boomeramg'
    petsc_options_iname = '-pc_type'
    petsc_options_value = 'lu'
[]

[Outputs]
    exodus = true
[]