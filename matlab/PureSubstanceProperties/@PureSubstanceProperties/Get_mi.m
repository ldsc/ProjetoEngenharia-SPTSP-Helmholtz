function obj = Get_mi(obj)
x=(1+obj.D*obj.fr_d-obj.D*obj.T*obj.fr_dt)^2;
x=x-((obj.T^2)*(obj.fr_tt+obj.fi_tt)*(1+2*obj.D*obj.fr_d+(obj.D^2)*obj.fr_dd));
x=-(obj.D*obj.fr_d+(obj.D^2)*obj.fr_dd+obj.D*obj.T*obj.fr_dt)/x;
obj.Joule_Thomson_coef=x/(obj.R*obj.d);
obj.Joule_Thomson_coef=obj.Joule_Thomson_coef*1000;
end

