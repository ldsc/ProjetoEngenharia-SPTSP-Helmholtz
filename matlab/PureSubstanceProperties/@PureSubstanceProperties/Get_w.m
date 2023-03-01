function obj = Get_w( obj )
x=1+2*obj.D*obj.fr_d+(obj.D^2)*obj.fr_dd;
x=x-((1+obj.D*obj.fr_d-obj.D*obj.T*obj.fr_dt)^2)/((obj.T^2)*(obj.fr_tt+obj.fi_tt));
obj.speed_sound=((x*obj.R*obj.t)^(1/2))*31.623164418947891;
end

