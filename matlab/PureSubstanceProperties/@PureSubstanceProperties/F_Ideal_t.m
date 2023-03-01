function obj = F_Ideal_t(obj)
obj.fi_t=obj.coef_i1(2)+obj.coef_i1(3)/obj.T;
for n=1:obj.n_coef_ideal;
  obj.fi_t=obj.fi_t+(obj.coef_i2(n,1)*obj.coef_i2(n,2)*((1-obj.e^(-obj.coef_i2(n,2)*obj.T))^(-1)-1));
end 
if obj.tc==126.192
   obj.fi=obj.fi-obj.coef_i1(4)/obj.T^2-2*obj.coef_i1(5)/obj.T^3-3*obj.coef_i1(6)/obj.T^4;
end
end

