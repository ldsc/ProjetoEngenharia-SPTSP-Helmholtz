function obj = Get_throttle( obj )
obj.isot_throttle_coef=(1-((1+obj.D*obj.fr_d-obj.D*obj.T*obj.fr_dt)/(1+2*obj.D*obj.fr_d+(obj.D^2)*obj.fr_dd)));
obj.isot_throttle_coef=obj.isot_throttle_coef/obj.d;
end

