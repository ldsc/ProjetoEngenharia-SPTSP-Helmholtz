function obj = Get_enthalpy( obj )
obj.enthalpy=(1+obj.T*(obj.fi_t+obj.fr_t)+obj.D*obj.fr_d)*obj.R*obj.t;
obj=obj.Get_enthalpy_t;
obj=obj.Get_enthalpy_d;
end

