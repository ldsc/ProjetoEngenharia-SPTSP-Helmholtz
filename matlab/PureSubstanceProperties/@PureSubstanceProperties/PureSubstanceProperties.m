classdef PureSubstanceProperties
    %Class for calculating pure substance properties based on the Helmholtz free energy.
    properties
    t=0 %temperature in K
    d=0 %specific mass in g/cm^3
    pressure=0 %in Bar
    isothermal_compressibility=0 %in 1/Bar
    enthalpy=0 %in kJ/kg
    entropy=0 %in kJ/kg.K
    internal_energy=0 %in kJ/kg
    Gibbs_energy=0 %in kJ/kg
    isochoric_heat_C=0 %in kJ/kg.K
    isobaric_heat_C=0 %in kJ/kg.K
    saturated_liq_heat_C=0 %in kJ/kg.K
    speed_sound=0 %in m/s
    Joule_Thomson_coef=0 %in K/MPa
    isot_throttle_coef=0
    isentropic_t_p_coef=0
    second_virial=0
    third_virial=0   
    sat_liquid_heat_C=0
    end
    properties (Hidden)
    T=0 %inverse reduced temperature
    D=0 %reduced pressure
    dg=0 %pressure of the saturated gas
    Dg=0 %reduced pressure of the saturated gas
    d_p=0 %derivative of specific mass in relation to pressure
    %_d means derivative in relation to specific mass, _t to temperature and _p to pressure
    pressure_d=0
    pressure_t=0
    pressure_dt=0
    pressure_dd=0
    isothermal_compressibility_d=0
    isothermal_compressibility_t=0
    isothermal_compressibility_p=0
    entropy_d=0
    entropy_t=0
    entropy_p=0
    internal_energy_d=0
    internal_energy_t=0
    internal_energy_p=0
    enthalpy_d=0
    enthalpy_t=0 
    enthalpy_p=0 
    Gibbs_energy_d=0 
    Gibbs_energy_t=0
    Gibbs_energy_p=0
    isochoric_heat_C_t=0
    isochoric_heat_C_d=0
    isochoric_heat_C_p=0
    isobaric_heat_C_d=0  
    isobaric_heat_C_t=0 
    isobaric_heat_C_p=0 
    speed_sound_t=0
    speed_sound_d=0
    speed_sound_p=0
    Joule_Thomson_coef_d=0
    Joule_Thomson_coef_t=0
    Joule_Thomson_coef_p=0
    isot_throttle_coef_d=0
    isot_throttle_coef_t=0
    isot_throttle_coef_p=0
    isentropic_t_p_coef_d=0
    isentropic_t_p_coef_t=0
    isentropic_t_p_coef_p=0
    second_virial_d=0
    second_virial_t=0
    second_virial_p=0
    third_virial_d=0 
    third_virial_t=0
    third_virial_p=0

    end
    properties (Constant, Hidden)
    e=2.718281828459046
    end
    properties (SetAccess = private, GetAccess = private)
    %fi means the ideal part of the equation, fr the residual
    %d and t after the underline represent the number of partial
    %derivatives in relarion to specific mass and temperature, repectively
    fi=0 
    fi_t=0
    fi_tt=0 
    fi_ttt=0
    fi_d=0
    fr=0 
    fr_g=0
    fr_t=0
    fr_g_t=0
    fr_tt=0 
    fr_ttt=0
    fr_d=0 
    fr_dt=0
    fr_ddt=0
    fr_dtt=0
    fr_t_g=0
    fr_dd=0
    fr_ddd=0
    tc %critical temperature, K
    dc %critical specific mass, kg/m^3
    substance %H20, CO2, N2, CH4, C2H6, nC4H10, iC4H10
    R %specific gas constant, kJ/(kgK)
    
    %coefficient matrixes
    coef_pol
    coef_exp
    coef_gauss
    coef_nonanalitic
    coef_i1
    coef_i2
    %number of sums for calculating the Helmholtz free energy
    n_coef_ideal
    n_coef_pol
    n_coef_exp
    n_coef_gauss
    n_coef_nonanalitic    
    end  
    methods
%-------Constructor---------------------------------
        function obj = PureSubstanceProperties(t,d,calculate,substance,d2)
             obj.substance=substance;
             obj=obj.Get_coefficients;
             if strcmp(calculate,'saturated')
            obj=obj.set_T(t);
            obj=obj.set_Dg(d2);
            obj=obj.set_D(d);
            obj=obj.Get_Helmholtz_s;
            obj=obj.Get_pressure;
            obj=obj.Get_pressure_s_t;
            obj=obj.Get_Cs;
             end
             if  strcmp(calculate,'none')
            obj=obj.set_T(t);
            obj=obj.set_D(d);
            obj=obj.Get_Helmholtz;
             elseif  strcmp(calculate,'all')
            obj=obj.set_T(t);
            obj=obj.set_D(d);
            obj=obj.Get_Helmholtz;
            obj=obj.Get_all;
            obj=obj.Get_all_d;
             end
        end      
%-------Input Functions------------------------------
        function obj = set_T(obj,t)
      obj.t=t;
      obj.T =(obj.tc/t);
        end
        function obj = set_D(obj,d)
      d=d*1000;
      obj.d=d;
      obj.D =(d/obj.dc);
        end
        function obj = set_Dg(obj,d)
      d=d*1000;      
      obj.dg=d;
      obj.Dg =(d/obj.dc);
        end
%------Adquiring properties from Helmholtz-----------
      obj = Get_coefficients(obj) % coeficientes para cada substância (hierarquia classes substância)
      obj = Get_all(obj) 
      obj = Get_pressure(obj) % calcula pressão para substância (temperatura, densidade, coeficientes)
      obj = Get_enthalpy(obj)
      obj = Get_entropy(obj)
      obj = Get_Cv(obj)
      obj = Get_u(obj)
      obj = Get_Gibbs(obj)
      obj = Get_Cp(obj)
      obj = Get_Cs(obj)
      obj = Get_w(obj)
      obj = Get_mi(obj)
      obj = Get_throttle(obj)
      obj = Get_isentropic(obj)
      obj = Get_second_v(obj)
      obj = Get_third_v(obj)
      obj = Get_compressibility(obj)
%-----Getting the properties' derivatives------------
      obj = Get_all_d(obj)
      obj = Get_pressure_d(obj)
      obj = Get_pressure_t(obj)
      obj = Get_pressure_dt(obj)
      obj = Get_pressure_dd(obj)
      obj = Get_compressibility_d(obj)
      obj = Get_compressibility_t(obj)
      obj = Get_compressibility_p(obj)
      obj = Get_pressure_s_t(obj)
      obj = Get_entropy_d(obj)
      obj = Get_entropy_t(obj)
      obj = Get_u_d(obj)
      obj = Get_u_t(obj)
      obj = Get_enthalpy_d(obj)
      obj = Get_enthalpy_t(obj) 
      obj = Get_Gibbs_d(obj)
      obj = Get_Gibbs_t(obj)
      obj = Get_Cv_d(obj)
      obj = Get_Cv_t(obj)
      obj = Get_Cp_d(obj)
      obj = Get_Cp_t(obj)
      obj = Get_w_d(obj)
      obj = Get_w_t(obj)
      obj = Get_mi_d(obj)
      obj = Get_mi_t(obj)
      obj = Get_throttle_d(obj)
      obj = Get_throttle_t(obj)
      obj = Get_isentropic_d(obj)
      obj = Get_isentropic_t(obj)
      obj = Get_second_v_t(obj)
      obj = Get_third_v_t(obj)
%-----Adimensional Helmholtz and derivatives---------
      obj = F_Ideal(obj)
      obj = F_Ideal_t(obj)
      obj = F_Ideal_tt(obj)
      obj = F_Ideal_ttt(obj)
      obj = F_Ideal_d(obj)
      obj = Get_Fr(obj)
      obj = Get_Fr_g(obj)
      obj = Get_Fr_g_t(obj)
      obj = Get_Fr_d(obj)
      obj = Get_Fr_t(obj)
      obj = Get_Fr_tt(obj)
      obj = Get_Fr_ttt(obj)
      obj = Get_Fr_dd(obj)
      obj = Get_Fr_ddd(obj)
      obj = Get_Fr_dt(obj)
      obj = Get_Fr_dtt(obj)
      obj = Get_Fr_ddt(obj)
      obj = Get_Helmholtz(obj)
      obj = Get_Helmholtz_s(obj)
       
      function disp(obj)  
   display(['Calculating the properties of ',obj.substance]);
   display ---------------------------------------------------------------------;
   if obj.t~=0
   if obj.pressure~=0
   display(['Pressure= ',num2str(obj.pressure),' Bar']);
   display(['Pressure_t= ',num2str(obj.pressure_t)]);
   if obj.fr_g==0
   display(['Pressure_d= ',num2str(obj.pressure_d)]);
   end
   display ------------------------------------------- ; 
   end
   if obj.enthalpy~=0
   display(['Enthalpy= ',num2str(obj.enthalpy),' kJ/kg']);
   display(['Enthalpy_d= ',num2str(obj.enthalpy_d)]);
   display(['Enthalpy_t= ',num2str(obj.enthalpy_t)]);
   display(['Enthalpy_p= ',num2str(obj.enthalpy_p)]);
   display ------------------------------------------- ;
   end
   if obj.isothermal_compressibility~=0
   display(['Isothermal Compressibility= ',num2str(obj.isothermal_compressibility),' 1/Bar']);
   display(['Isothermal Compressibility_d= ',num2str(obj.isothermal_compressibility_d)]);
   display(['Isothermal Compressibility_t= ',num2str(obj.isothermal_compressibility_t)]);
   display(['Isothermal Compressibility_p= ',num2str(obj.isothermal_compressibility_p)]);
   display ------------------------------------------- ;
   end
   if obj.entropy~=0
   display(['Entropy= ',num2str(obj.entropy),' kJ/kg*K']);
   display(['Entropy_d= ',num2str(obj.entropy_d)]);
   display(['Entropy_t= ',num2str(obj.entropy_t)]);
   display(['Entropy_p= ',num2str(obj.entropy_p)]);
   display ------------------------------------------- ;
   end
   if obj.internal_energy~=0
   display(['Internal Energy= ',num2str(obj.internal_energy),' kJ/kg']);
   display(['Internal Energy_d= ',num2str(obj.internal_energy_d)]);
   display(['Internal Energy_t= ',num2str(obj.internal_energy_t)]);
   display(['Internal Energy_p= ',num2str(obj.internal_energy_p)]);
   display ------------------------------------------- ;
   end
   if obj.Gibbs_energy~=0
   display(['Gibbs Energy= ',num2str(obj.Gibbs_energy),' kJ/kg']);
   display(['Gibbs Energy_d= ',num2str(obj.Gibbs_energy_d)]);
   display(['Gibbs Energy_t= ',num2str(obj.Gibbs_energy_t)]);
   display(['Gibbs Energy_p= ',num2str(obj.Gibbs_energy_p)]);
   display ------------------------------------------- ;
   end
   if obj.isochoric_heat_C~=0
   display(['Isochoric Heat Capacity= ',num2str(obj.isochoric_heat_C),' kJ/kg*K']);
   display(['Isochoric Heat Capacity_t= ',num2str(obj.isochoric_heat_C_t)]);
   display(['Isochoric Heat Capacity_d= ',num2str(obj.isochoric_heat_C_d)]);
   display(['Isochoric Heat Capacity_p= ',num2str(obj.isochoric_heat_C_p)]);
   display ------------------------------------------- ;
   end
   if obj.isobaric_heat_C~=0
   display([ 'Isobaric Heat Capacity= ',num2str(obj.isobaric_heat_C),' kJ/kg*K']);
   display([ 'Isobaric Heat Capacity_t= ',num2str(obj.isobaric_heat_C_t)]);
   display([ 'Isobaric Heat Capacity_d= ',num2str(obj.isobaric_heat_C_d)]);
   display([ 'Isobaric Heat Capacity_p= ',num2str(obj.isobaric_heat_C_p)]);
   display ------------------------------------------- ;
   end
   if obj.saturated_liq_heat_C~=0
   display([ 'Saturated Liquid Heat Capacity= ',num2str(obj.saturated_liq_heat_C),' kJ/kg*K']);
   display ------------------------------------------- ;
   end
   if obj.speed_sound~=0
   display([ 'Speed of Sound=',num2str(obj.speed_sound),' m/s']);
   display([ 'Speed of Sound_t=',num2str(obj.speed_sound_t)]);
   display([ 'Speed of Sound_d=',num2str(obj.speed_sound_d)]);
   display([ 'Speed of Sound_p=',num2str(obj.speed_sound_p)]);
   display ------------------------------------------- ;
   end
   if obj.Joule_Thomson_coef~=0
   display(['Joule-Thomson Coefficient= ',num2str(obj.Joule_Thomson_coef),' K/Bar']);
   display(['Joule-Thomson Coefficient_t= ',num2str(obj.Joule_Thomson_coef_t)]);
   display(['Joule-Thomson Coefficient_d= ',num2str(obj.Joule_Thomson_coef_d)]);
   display(['Joule-Thomson Coefficient_p= ',num2str(obj.Joule_Thomson_coef_p)]);
   display ------------------------------------------- ;
   end
   if obj.isot_throttle_coef~=0
   display(['Isotermic Throttle Coefficient= ',num2str(obj.isot_throttle_coef)]);
   display(['Isotermic Throttle Coefficient_t= ',num2str(obj.isot_throttle_coef_t)]);
   display(['Isotermic Throttle Coefficient_d= ',num2str(obj.isot_throttle_coef_d)]);
   display(['Isotermic Throttle Coefficient_p= ',num2str(obj.isot_throttle_coef_p)]);
   display ------------------------------------------- ;
   end
   if obj.isentropic_t_p_coef~=0
   display(['Isentropic Temperature-Pressure Coefficient= ',num2str(obj.isentropic_t_p_coef)]);
   display(['Isentropic Temperature-Pressure Coefficient_t= ',num2str(obj.isentropic_t_p_coef_t)]);
   display(['Isentropic Temperature-Pressure Coefficient_d= ',num2str(obj.isentropic_t_p_coef_d)]);
   display(['Isentropic Temperature-Pressure Coefficient_p= ',num2str(obj.isentropic_t_p_coef_p)]);
   display ------------------------------------------- ;
   end
   if obj.second_virial~=0
   display([ 'Second Virial Coefficient= ',num2str(obj.second_virial)]);
   display([ 'Second Virial Coefficient_t= ',num2str(obj.second_virial_t)]);
   display ------------------------------------------- ;
   end
   if obj.third_virial~=0
   display([ 'Third Virial Coefficient= ',num2str(obj.third_virial)]);
   display([ 'Third Virial Coefficient_t= ',num2str(obj.third_virial_t)]);
   end
   end 
   display ---------------------------------------------------------------------;
   end
   end 
end




