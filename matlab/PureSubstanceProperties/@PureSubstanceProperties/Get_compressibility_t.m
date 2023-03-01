function obj = Get_compressibility_t( obj )
obj=obj.Get_pressure_dt;
obj.isothermal_compressibility_t=-obj.pressure_dt/(obj.d*obj.pressure_d^2);
end

