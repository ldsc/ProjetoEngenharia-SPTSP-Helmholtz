function obj = Get_Cv_t( obj )
T=obj.T;
obj.isochoric_heat_C_t=obj.R*T^2*(T*(obj.fr_ttt+obj.fi_ttt)+2*(obj.fr_tt+obj.fi_tt))/obj.t;
end

