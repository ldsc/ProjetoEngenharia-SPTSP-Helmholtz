function obj = Get_pressure_dt( obj )
obj.pressure_dt=-obj.R*((2*obj.D*obj.fr_dt+obj.D^2*obj.fr_ddt)*obj.T-(1+2*obj.D*obj.fr_d+obj.D^2*obj.fr_dd))/100;
end

