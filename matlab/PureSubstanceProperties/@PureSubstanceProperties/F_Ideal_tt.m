function obj = F_Ideal_tt(obj)
%Second temperature derivative of the ideal part
obj.fi_tt=(-obj.coef_i1(3)/(obj.T^2));
for n=1:obj.n_coef_ideal;
  obj.fi_tt=obj.fi_tt-(obj.coef_i2(n,1)*((obj.coef_i2(n,2))^2)*(obj.e^(-obj.coef_i2(n,2)*obj.T))*((1-obj.e^(-obj.coef_i2(n,2)*obj.T))^(-2)));
end 
if obj.tc==126.192
   obj.fi=obj.fi+2*obj.coef_i1(4)/obj.T^3+6*obj.coef_i1(5)/obj.T^4+12*obj.coef_i1(6)/obj.T^5;
end
end