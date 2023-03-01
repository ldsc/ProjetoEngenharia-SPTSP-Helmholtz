function obj = Get_compressibility( obj )
if obj.d_p==0
    obj=obj.Get_pressure_d;
end
obj.isothermal_compressibility=obj.d_p/obj.d;
end

