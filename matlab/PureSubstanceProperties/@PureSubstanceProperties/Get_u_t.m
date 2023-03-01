function obj = Get_u_t( obj )
obj.internal_energy_t=-obj.tc*obj.R*(obj.fr_tt+obj.fi_tt)*obj.T/obj.t;
end

