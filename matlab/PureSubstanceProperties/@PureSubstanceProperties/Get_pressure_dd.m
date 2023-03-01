function obj = Get_pressure_dd( obj )
obj.pressure_dd=obj.t*obj.R*(2*obj.fr_d+4*obj.D*obj.fr_dd+obj.D^2*obj.fr_ddd)/(100*obj.dc);
end

