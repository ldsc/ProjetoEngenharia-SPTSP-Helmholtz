function varargout = PureSub(varargin)
% PURESUB MATLAB code for PureSub.fig
%      PURESUB, by itself, creates a new PURESUB or raises the existing
%      singleton*.
%
%      H = PURESUB returns the handle to a new PURESUB or the handle to
%      the existing singleton*.
%
%      PURESUB('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in PURESUB.M with the given input arguments.
%
%      PURESUB('Property','Value',...) creates a new PURESUB or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before PureSub_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to PureSub_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help PureSub

% Last Modified by GUIDE v2.5 22-Sep-2014 16:13:51

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @PureSub_OpeningFcn, ...
                   'gui_OutputFcn',  @PureSub_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before PureSub is made visible.
function PureSub_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to PureSub (see VARARGIN)

% Choose default command line output for PureSub
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes PureSub wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = PureSub_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on selection change in Substance.
function Substance_Callback(hObject, eventdata, handles)
% hObject    handle to Substance (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns Substance contents as cell array
%        contents{get(hObject,'Value')} returns selected item from Substance


% --- Executes during object creation, after setting all properties.
function Substance_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Substance (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in DerivativesCheck.
function DerivativesCheck_Callback(hObject, eventdata, handles)
% hObject    handle to DerivativesCheck (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of DerivativesCheck



function TemperatureInput_Callback(hObject, eventdata, handles)
% hObject    handle to TemperatureInput (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% Hints: get(hObject,'String') returns contents of density as text
%        str2double(get(hObject,'String')) returns contents of density as a double
%input de temperature

if isnan(get(hObject, 'String'))
    set(hObject, 'String', 0);
    errordlg('Input must be a number','Error');
end

% Save the new density value


% --- Executes during object creation, after setting all properties.
function TemperatureInput_CreateFcn(hObject, eventdata, handles)
% hObject    handle to TemperatureInput (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in TemperatureUnit.
function TemperatureUnit_Callback(hObject, eventdata, handles)
% hObject    handle to TemperatureUnit (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns TemperatureUnit contents as cell array
%        contents{get(hObject,'Value')} returns selected item from TemperatureUnit


% --- Executes during object creation, after setting all properties.
function TemperatureUnit_CreateFcn(hObject, eventdata, handles)
% hObject    handle to TemperatureUnit (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function DensityInput_Callback(hObject, eventdata, handles)
% hObject    handle to DensityInput (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of DensityInput as text
%        str2double(get(hObject,'String')) returns contents of DensityInput as a double

if isnan(get(hObject, 'String'))
    set(hObject, 'String', 0);
    errordlg('Input must be a number','Error');
end

% Save the new density value


% --- Executes during object creation, after setting all properties.
function DensityInput_CreateFcn(hObject, eventdata, handles)
% hObject    handle to DensityInput (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in DensityUnit.
function DensityUnit_Callback(hObject, eventdata, handles)
% hObject    handle to DensityUnit (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns DensityUnit contents as cell array
%        contents{get(hObject,'Value')} returns selected item from DensityUnit


% --- Executes during object creation, after setting all properties.
function DensityUnit_CreateFcn(hObject, eventdata, handles)
% hObject    handle to DensityUnit (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in PropertiesCheck.
function PropertiesCheck_Callback(hObject, eventdata, handles)
% hObject    handle to PropertiesCheck (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if get(hObject,'Value')==1
    set(handles.PressureCheck, 'Value', 1);
    set(handles.EnthalpyCheck, 'Value', 1);
    set(handles.EntropyCheck, 'Value', 1);
    set(handles.InternalEnergyCheck, 'Value', 1);
    set(handles.GibbsCheck, 'Value', 1);
    set(handles.CvCheck, 'Value', 1);
    set(handles.CpCheck, 'Value', 1);
    set(handles.CompressibilityCheck, 'Value', 1);
    set(handles.SpeedSoundCheck, 'Value', 1);
    set(handles.JouleThomsonCheck, 'Value', 1);
    set(handles.ThrottleCheck, 'Value', 1);
    set(handles.IsentropicCheck, 'Value', 1);
    set(handles.SecondVirialCheck, 'Value', 1);
    set(handles.ThirdVirialCheck, 'Value', 1);
end
if get(hObject,'Value')==0
    set(handles.PressureCheck, 'Value', 0);
    set(handles.EnthalpyCheck, 'Value', 0);
    set(handles.EntropyCheck, 'Value', 0);
    set(handles.InternalEnergyCheck, 'Value', 0);
    set(handles.GibbsCheck, 'Value', 0);
    set(handles.CvCheck, 'Value', 0);
    set(handles.CpCheck, 'Value', 0);
    set(handles.CompressibilityCheck, 'Value', 0);
    set(handles.SpeedSoundCheck, 'Value', 0);
    set(handles.JouleThomsonCheck, 'Value', 0);
    set(handles.ThrottleCheck, 'Value', 0);
    set(handles.IsentropicCheck, 'Value', 0);
    set(handles.SecondVirialCheck, 'Value', 0);
    set(handles.ThirdVirialCheck, 'Value', 0);
end

% Hint: get(hObject,'Value') returns toggle state of PropertiesCheck


% --- Executes on button press in PressureCheck.
function PressureCheck_Callback(hObject, eventdata, handles)
% hObject    handle to PressureCheck (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of PressureCheck


% --- Executes on button press in EnthalpyCheck.
function EnthalpyCheck_Callback(hObject, eventdata, handles)
% hObject    handle to EnthalpyCheck (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of EnthalpyCheck


% --- Executes on button press in EntropyCheck.
function EntropyCheck_Callback(hObject, eventdata, handles)
% hObject    handle to EntropyCheck (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of EntropyCheck


% --- Executes on button press in InternalEnergyCheck.
function InternalEnergyCheck_Callback(hObject, eventdata, handles)
% hObject    handle to InternalEnergyCheck (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of InternalEnergyCheck


% --- Executes on button press in GibbsCheck.
function GibbsCheck_Callback(hObject, eventdata, handles)
% hObject    handle to GibbsCheck (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of GibbsCheck


% --- Executes on button press in CvCheck.
function CvCheck_Callback(hObject, eventdata, handles)
% hObject    handle to CvCheck (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of CvCheck


% --- Executes on button press in CpCheck.
function CpCheck_Callback(hObject, eventdata, handles)
% hObject    handle to CpCheck (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of CpCheck


% --- Executes on button press in CompressibilityCheck.
function CompressibilityCheck_Callback(hObject, eventdata, handles)
% hObject    handle to CompressibilityCheck (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of CompressibilityCheck


% --- Executes on button press in SpeedSoundCheck.
function SpeedSoundCheck_Callback(hObject, eventdata, handles)
% hObject    handle to SpeedSoundCheck (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of SpeedSoundCheck


% --- Executes on button press in JouleThomsonCheck.
function JouleThomsonCheck_Callback(hObject, eventdata, handles)
% hObject    handle to JouleThomsonCheck (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of JouleThomsonCheck


% --- Executes on button press in ThrottleCheck.
function ThrottleCheck_Callback(hObject, eventdata, handles)
% hObject    handle to ThrottleCheck (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of ThrottleCheck


% --- Executes on button press in IsentropicCheck.
function IsentropicCheck_Callback(hObject, eventdata, handles)
% hObject    handle to IsentropicCheck (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of IsentropicCheck



% --- Executes on button press in SecondVirialCheck.
function SecondVirialCheck_Callback(hObject, eventdata, handles)
% hObject    handle to SecondVirialCheck (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of SecondVirialCheck


% --- Executes on button press in ThirdVirialCheck.
function ThirdVirialCheck_Callback(hObject, eventdata, handles)
% hObject    handle to ThirdVirialCheck (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of ThirdVirialCheck
function ResetDisplays(handles)
set(handles.PressureDisplay, 'String', ' ');
    set(handles.EnthalpyDisplay, 'String', ' ');
    set(handles.EntropyDisplay, 'String', ' ');
    set(handles.InternalEnergyDisplay, 'String', ' ');
    set(handles.GibbsEnergyDisplay, 'String', ' ');
    set(handles.CvDisplay, 'String', ' ');
    set(handles.CpDisplay, 'String', ' ');
    set(handles.KDisplay, 'String', ' ');
    set(handles.WDisplay, 'String', ' ');
    set(handles.JTDisplay, 'String', ' ');
    set(handles.ThrottleDisplay, 'String', ' ');
    set(handles.IsentropicDisplay, 'String', ' ');
    set(handles.SecondVirialDisplay, 'String', ' ');
    set(handles.ThirdVirialDisplay, 'String', ' ');
    
function SetDisplays(handles,n)
if n.pressure~=0
    set(handles.PressureDisplay, 'String', ['Pressure: ',num2str(n.pressure),' Bar']);
end
if n.enthalpy~=0
    set(handles.EnthalpyDisplay, 'String', ['Enthalpy: ',num2str(n.enthalpy),' kJ/kg']);
end
if n.entropy~=0
    set(handles.EntropyDisplay, 'String', ['Entropy: ',num2str(n.entropy),' kJ/kg*K']);
end
if n.internal_energy~=0
    set(handles.InternalEnergyDisplay, 'String', ['Internal Energy: ',num2str(n.internal_energy),' kJ/kg']);
end
if n.Gibbs_energy~=0
    set(handles.GibbsEnergyDisplay, 'String', ['Gibbs Energy: ',num2str(n.Gibbs_energy),' kJ/kg']);
end
if n.isochoric_heat_C~=0
    set(handles.CvDisplay, 'String', ['Isochoric Heat Capacity: ',num2str(n.isochoric_heat_C),' kJ/kg*K']);
end
if n.isobaric_heat_C~=0
    set(handles.CpDisplay, 'String', ['Isobaric Heat Capacity: ',num2str(n.isobaric_heat_C),' kJ/kg*K']);
end
if n.isothermal_compressibility~=0
    set(handles.KDisplay, 'String', ['Isothermal Compressibility: ',num2str(n.isothermal_compressibility),' 1/Bar']);
end
if n.speed_sound~=0
    set(handles.WDisplay, 'String', ['Speed of Sound: ',num2str(n.speed_sound),' m/s']);
end
if n.Joule_Thomson_coef~=0
    set(handles.JTDisplay, 'String', ['Joule-Thomson Coefficient= ',num2str(n.Joule_Thomson_coef),' K/Bar']);
end
if n.isot_throttle_coef~=0
    set(handles.ThrottleDisplay, 'String', ['Isotermic Throttle Coefficient: ',num2str(n.isot_throttle_coef)]);
end
if n.isentropic_t_p_coef~=0
    set(handles.IsentropicDisplay, 'String', ['Isentropic Temperature-Pressure Coefficient: ',num2str(n.isentropic_t_p_coef)]);
end
if n.second_virial~=0
    set(handles.SecondVirialDisplay, 'String', ['Second Virial Coefficient: ',num2str(n.second_virial)]);
end
if n.third_virial~=0
    set(handles.ThirdVirialDisplay, 'String', ['Third Virial Coefficient: ',num2str(n.third_virial)]);
end

% --- Executes on button press in Calculate.
function Calculate_Callback(hObject, eventdata, handles)
% hObject    handle to Calculate (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
ResetDisplays(handles);
subs = get(handles.Substance, 'Value');
mintemp=[251.165,216,63.151,90.7,90.37,134.895,113.730];
maxtemp=[1273,1100,1000,625,675,575,575];
molweight=[18.01528,44.01,28.013,16.04,30.7,58.12,58.12];
%converting density units
dunit = get(handles.DensityUnit, 'Value');
switch dunit
    case 1
        density = str2double(get(handles.DensityInput, 'String'));
    case 2
        density = str2double(get(handles.DensityInput, 'String'))*molweight(subs);
    case 3
        density = str2double(get(handles.DensityInput, 'String'))/1000;
    case 4
        density = str2double(get(handles.DensityInput, 'String'))*453.5924/28316.8466;
end
%converting temperature units
tunit = get(handles.TemperatureUnit, 'Value');
switch tunit
    case 1
        temperature = str2double(get(handles.TemperatureInput, 'String'));
    case 2
        temperature = str2double(get(handles.TemperatureInput, 'String'))+273.15;
    case 3
        temperature = (str2double(get(handles.TemperatureInput, 'String'))+459.67)/1.8;
    case 4
        temperature = str2double(get(handles.TemperatureInput, 'String'))/1.8;
end
if temperature<mintemp(subs)
    errordlg('Temperature below melting point','Error');
else
if temperature>maxtemp(subs)
    errordlg('Temperature above precise level, properties may be wrong','Warning:');
end
%getting substance
switch subs
    case 1
        s='H2O';
    case 2
        s='CO2';
    case 3
        s='N2';
    case 4
        s='CH4';
    case 5
        s='C2H6';
    case 6
        s='nC4H10';
    case 7
        s='iC4H10';
end
if get(handles.PropertiesCheck,'Value')==1
    n = PureSubstanceProperties(temperature,density,'all',s);
    SetDisplays(handles, n)
else
n = PureSubstanceProperties(temperature,density,'none',s);
if get(handles.PressureCheck, 'Value')==1
n=n.Get_pressure;
SetDisplays(handles, n)
end
if get(handles.EnthalpyCheck, 'Value')==1
    n=n.Get_enthalpy;
    set(handles.EnthalpyDisplay, 'String', ['Enthalpy: ',num2str(n.enthalpy),' kJ/kg']);
end
if get(handles.EntropyCheck, 'Value')==1
    n=n.Get_entropy;
    set(handles.EntropyDisplay, 'String', ['Entropy: ',num2str(n.entropy),' kJ/kg*K']);
end
if get(handles.InternalEnergyCheck, 'Value')==1
    n=n.Get_u;
    set(handles.InternalEnergyDisplay, 'String', ['Internal Energy: ',num2str(n.internal_energy),' kJ/kg']);
end
if get(handles.GibbsCheck, 'Value')==1
    n=n.Get_Gibbs;
    set(handles.GibbsEnergyDisplay, 'String', ['Gibbs Energy: ',num2str(n.Gibbs_energy),' kJ/kg']);
end
if get(handles.CvCheck, 'Value')==1
    n=n.Get_Cv;
    set(handles.CvDisplay, 'String', ['Isochoric Heat Capacity: ',num2str(n.isochoric_heat_C),' kJ/kg*K']);
end
if get(handles.CpCheck, 'Value')==1
    n=n.Get_Cp;
    set(handles.CpDisplay, 'String', ['Isobaric Heat Capacity: ',num2str(n.isobaric_heat_C),' kJ/kg*K']);
end
if get(handles.CompressibilityCheck, 'Value')==1
    n=n.Get_compressibility;
    set(handles.KDisplay, 'String', ['Isothermal Compressibility: ',num2str(n.isothermal_compressibility),' 1/Bar']);
end
if get(handles.SpeedSoundCheck, 'Value')==1
    n=n.Get_w;
    set(handles.WDisplay, 'String', ['Speed of Sound: ',num2str(n.speed_sound),' m/s']);
end
if get(handles.JouleThomsonCheck, 'Value')==1
    n=n.Get_mi;
    set(handles.JTDisplay, 'String', ['Joule-Thomson Coefficient: ',num2str(n.Joule_Thomson_coef),' K/Bar']);
end
if get(handles.ThrottleCheck, 'Value')==1
    n=n.Get_throttle;
    set(handles.ThrottleDisplay, 'String', ['Isotermic Throttle Coefficient: ',num2str(n.isot_throttle_coef)]);
end
if get(handles.IsentropicCheck, 'Value')==1
    n=n.Get_isentropic;
    set(handles.IsentropicDisplay, 'String', ['Isentropic Temperature-Pressure Coefficient: ',num2str(n.isentropic_t_p_coef)]);
end
if get(handles.SecondVirialCheck, 'Value')==1
    n=n.Get_second_v;
    set(handles.SecondVirialDisplay, 'String', ['Second Virial Coefficient: ',num2str(n.second_virial)]);
end
if get(handles.ThirdVirialCheck, 'Value')==1
    n=n.Get_third_v;
    set(handles.ThirdVirialDisplay, 'String', ['Third Virial Coefficient: ',num2str(n.third_virial)]);
end
end
end
