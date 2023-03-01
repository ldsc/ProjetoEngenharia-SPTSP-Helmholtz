clc
mintemp=[251.165,216,90.7,90.37,134.895,113.730,63.151];
maxtemp=[1273,1100,625,675,575,575,1000];
maxp=[10000,8000,10000,9000,690,350,22000];
molweight=[18.01528,44.01,16.04,30.7,58.12,58.12,28.013];
display('Equation for calculating termodynamic properties of pure substances');
display('For what substance do you want to calculate?');
display('1 - Water');
display('2 - Carbon Dioxide');
display('3 - Methane');
display('4 - Ethane');
display('5 - n-Butane');
display('6 - Isobutane');
display('7 - Nitrogen');
n=input(' ');
display(['Equation valid for temperatures above ',num2str(mintemp(n)),'K']);
display(['Precise for temperatures under ',num2str(maxtemp(n)),'K']);
display(['and pressures under ',num2str(maxp(n)),'Bar']);
t=input('Type the temperature in Kelvin: ');
if t<mintemp(n)
    error('Temperature below the melting curve');
end
if t>maxtemp(n)
    display('WARNING:Extrapolating beyond the equation''s temperature range, results may not be accurate');
end
display('Input type for specific mass:');
display('1 - g/cm^3');
display('2 - g-mol/cm^3');
op=input(' ');
d=input('Type the specific mass: ');
if op==2
d=d*molweight(n);
end
if n==1
j=PureSubstanceProperties(t,d,'all','H2O');
elseif n==2
j=PureSubstanceProperties(t,d,'all','CO2');
elseif n==3
j=PureSubstanceProperties(t,d,'all','CH4');
elseif n==4
j=PureSubstanceProperties(t,d,'all','C2H6');
elseif n==5
j=PureSubstanceProperties(t,d,'all','nC4H10');
elseif n==6
j=PureSubstanceProperties(t,d,'all','iC4H10');
elseif n==7
j=PureSubstanceProperties(t,d,'all','N2');
end
display ---------------------------------------------------------------------;
if op==2
display(['Temperature=',num2str(t),' Kelvin, Density=',num2str(d/molweight(n)),' g-mol/cm^3']);
else
display(['Temperature=',num2str(t),' Kelvin, Density=',num2str(d),' g/cm^3']);
end
disp(j);
