function obj = Get_pressure_d( obj )
obj.pressure_d=((1+2*obj.D*obj.fr_d+obj.D^2*obj.fr_dd)*obj.t*obj.R)/100;
obj.pressure_d=obj.pressure_d;
obj.d_p=1/obj.pressure_d;
end

