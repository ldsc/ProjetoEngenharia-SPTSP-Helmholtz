function obj = Get_compressibility_d( obj )
obj=obj.Get_pressure_dd;
obj.isothermal_compressibility_d=-(obj.pressure_dd/obj.pressure_d+1/obj.d)/(obj.pressure_d*obj.d);
end

