function obj = Get_enthalpy_t( obj )
obj.enthalpy_t=-obj.R*(obj.T^2*(obj.fi_tt+obj.fr_tt)+obj.T*obj.D*obj.fr_dt-(obj.D*obj.fr_d+1));
end

