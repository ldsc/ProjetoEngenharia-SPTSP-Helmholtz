function obj = Get_isentropic( obj )
x=(1+obj.D*obj.fr_d-obj.D*obj.T*obj.fr_dt)^2;
x=x-((obj.T^2)*(obj.fi_tt+obj.fr_tt)*(1+2*obj.D*obj.fr_d+(obj.D^2)*obj.fr_dd));
x=(1+obj.D*obj.fr_d-obj.D*obj.T*obj.fr_dt)/x;
obj.isentropic_t_p_coef=x/(obj.d*obj.R);
end

