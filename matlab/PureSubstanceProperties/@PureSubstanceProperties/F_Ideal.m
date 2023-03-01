function obj = F_Ideal(obj)
%Ideal part of the IPAWS-95 formulation
obj.fi=log(obj.D)+obj.coef_i1(1)+(obj.coef_i1(2)*obj.T)+(obj.coef_i1(3)*log(obj.T));
for n=1:obj.n_coef_ideal;
    obj.fi=obj.fi+(obj.coef_i2(n,1)*(log(1-(obj.e^(-(obj.coef_i2(n,2)*obj.T))))));
end 
if obj.tc==126.192
   obj.fi=obj.fi+obj.coef_i1(4)/obj.T+obj.coef_i1(5)/(obj.T^2)+obj.coef_i1(6)/(obj.T^3);
end
end

