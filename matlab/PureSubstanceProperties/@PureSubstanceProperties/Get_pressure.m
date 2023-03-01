function obj = Get_pressure( obj )
if obj.fr_g ==0
obj.pressure=((1+(obj.D*obj.fr_d))*obj.d*obj.t*obj.R);
obj.pressure=obj.pressure/100;
obj=obj.Get_pressure_d;
obj=obj.Get_pressure_t;
else
obj.pressure=obj.fr-obj.fr_g+log(obj.d)-log(obj.dg);
fator=(1/obj.dg)-(1/obj.d);
obj.pressure=obj.pressure*obj.R*obj.t/(100*fator);
end

