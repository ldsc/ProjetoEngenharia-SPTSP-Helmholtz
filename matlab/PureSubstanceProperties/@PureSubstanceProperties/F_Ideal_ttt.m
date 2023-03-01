function obj = F_Ideal_ttt(obj)
%Second temperature derivative of the ideal part
obj.fi_ttt=2*(obj.coef_i1(3)/(obj.T^3));
for n=1:obj.n_coef_ideal;
  obj.fi_ttt=obj.fi_ttt+(obj.coef_i2(n,1)*((obj.coef_i2(n,2))^3)*(obj.e^(-obj.coef_i2(n,2)*obj.T))*(1-obj.e^(-obj.coef_i2(n,2)*obj.T))^(-2)*(1+2*obj.e^(-obj.coef_i2(n,2)*obj.T)*(1-obj.e^(-obj.coef_i2(n,2)*obj.T))));
end 
if obj.tc==126.192
   obj.fi=obj.fi-6*obj.coef_i1(4)/obj.T^4-24*obj.coef_i1(5)/obj.T^5-60*obj.coef_i1(6)/obj.T^6;
end
end

