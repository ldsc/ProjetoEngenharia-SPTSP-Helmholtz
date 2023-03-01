function varargout = RotinaGrafica(varargin)
% ROTINAGRAFICA MATLAB code for RotinaGrafica.fig
%      ROTINAGRAFICA, by itself, creates a new ROTINAGRAFICA or raises the existing
%      singleton*.
%
%      H = ROTINAGRAFICA returns the handle to a new ROTINAGRAFICA or the handle to
%      the existing singleton*.
%
%      ROTINAGRAFICA('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in ROTINAGRAFICA.M with the given input arguments.
%
%      ROTINAGRAFICA('Property','Value',...) creates a new ROTINAGRAFICA or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before RotinaGrafica_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to RotinaGrafica_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help RotinaGrafica

% Last Modified by GUIDE v2.5 19-Oct-2014 22:29:36

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @RotinaGrafica_OpeningFcn, ...
                   'gui_OutputFcn',  @RotinaGrafica_OutputFcn, ...
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


% --- Executes just before RotinaGrafica is made visible.
function RotinaGrafica_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to RotinaGrafica (see VARARGIN)

% Choose default command line output for RotinaGrafica
handles.output = hObject;
% Update handles structure
guidata(hObject, handles);

% UIWAIT makes RotinaGrafica wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = RotinaGrafica_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in PlotButton.
function PlotButton_Callback(hObject, eventdata, handles)
% hObject    handle to PlotButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
axes(handles.Graphic);
cla;
vmin = str2double(get(handles.VarMin, 'String'));
vstep = str2double(get(handles.VarStep, 'String'));
vmax = str2double(get(handles.VarMax, 'String'));
fixed = str2double(get(handles.FixedValue, 'String'));
yaxis = get(handles.YAxis, 'Value');
cont=1;
subs = get(handles.Substance, 'Value');
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
Y=zeros((vmax-vmin)/vstep+1);
X=zeros((vmax-vmin)/vstep+1);
if get(handles.IsFixedV,'Value')
switch yaxis
    case 1
        for p=vmin:vstep:vmax
            n=PureSubstanceProperties(p,fixed,'none',s);
            n=n.Get_pressure;
            Y(cont)=n.pressure;
            X(cont)=p;
            cont=cont+1;
        end
    case 2
        for p=vmin:vstep:vmax
            n=PureSubstanceProperties(p,fixed,'none',s);
            n=n.Get_enthalpy;
            Y(cont)=n.enthalpy;
            X(cont)=p;
            cont=cont+1;
        end
    case 3
        for p=vmin:vstep:vmax
            n=PureSubstanceProperties(p,fixed,'none',s);
            n=n.Get_entropy;
            Y(cont)=n.entropy;
            X(cont)=p;
            cont=cont+1;
        end
    case 4
        for p=vmin:vstep:vmax
            n=PureSubstanceProperties(p,fixed,'none',s);
            n=n.Get_u;
            Y(cont)=n.internal_energy;
            X(cont)=p;
            cont=cont+1;
        end
    case 5
        for p=vmin:vstep:vmax
            n=PureSubstanceProperties(p,fixed,'none',s);
            n=n.Get_Gibbs;
            Y(cont)=n.Gibbs_energy;
            X(cont)=p;
            cont=cont+1;
        end
    case 6
        for p=vmin:vstep:vmax
            n=PureSubstanceProperties(p,fixed,'none',s);
            n=n.Get_Cv;
            Y(cont)=n.isochoric_heat_C;
            X(cont)=p;
            cont=cont+1;
        end
    case 7
        for p=vmin:vstep:vmax
            n=PureSubstanceProperties(p,fixed,'none',s);
            n=n.Get_Cp;
            Y(cont)=n.isobaric_heat_C;
            X(cont)=p;
            cont=cont+1;
        end
    case 8
        for p=vmin:vstep:vmax
            n=PureSubstanceProperties(p,fixed,'none',s);
            n=n.Get_compressibility;
            Y(cont)=n.isothermal_compressibility;
            X(cont)=p;
            cont=cont+1;
        end
    case 9
        for p=vmin:vstep:vmax
            n=PureSubstanceProperties(p,fixed,'none',s);
            n=n.Get_w;
            Y(cont)=n.speed_sound;
            X(cont)=p;
            cont=cont+1;
        end
    case 10
        for p=vmin:vstep:vmax
            n=PureSubstanceProperties(p,fixed,'none',s);
            n=n.Get_mi;
            Y(cont)=n.Joule_Thomson_coef;
            X(cont)=p;
            cont=cont+1;
        end
    case 11
        for p=vmin:vstep:vmax
            n=PureSubstanceProperties(p,fixed,'none',s);
            n=n.Get_throttle;
            Y(cont)=n.isot_throttle_coef;
            X(cont)=p;
            cont=cont+1;
        end
    case 12
        for p=vmin:vstep:vmax
            n=PureSubstanceProperties(p,fixed,'none',s);
            n=n.Get_isentropic;
            Y(cont)=n.isentropic_t_p_coef;
            X(cont)=p;
            cont=cont+1;
        end
    case 13
        for p=vmin:vstep:vmax
            n=PureSubstanceProperties(p,fixed,'none',s);
            n=n.Get_second_v;
            Y(cont)=n.second_virial;
            X(cont)=p;
            cont=cont+1;
        end
    case 14
        for p=vmin:vstep:vmax
            n=PureSubstanceProperties(p,fixed,'none',s);
            n=n.Get_third_v;
            Y(cont)=n.third_virial;
            X(cont)=p;
            cont=cont+1;
        end
end
else
    switch yaxis
    case 1
        for p=vmin:vstep:vmax
            n=PureSubstanceProperties(fixed,p,'none',s);
            n=n.Get_pressure;
            Y(cont)=n.pressure;
            X(cont)=p;
            cont=cont+1;
        end
    case 2
        for p=vmin:vstep:vmax
            n=PureSubstanceProperties(fixed,p,'none',s);
            n=n.Get_enthalpy;
            Y(cont)=n.enthalpy;
            X(cont)=p;
            cont=cont+1;
        end
    case 3
        for p=vmin:vstep:vmax
            n=PureSubstanceProperties(fixed,p,'none',s);
            n=n.Get_entropy;
            Y(cont)=n.entropy;
            X(cont)=p;
            cont=cont+1;
        end
    case 4
        for p=vmin:vstep:vmax
            n=PureSubstanceProperties(fixed,p,'none',s);
            n=n.Get_u;
            Y(cont)=n.internal_energy;
            X(cont)=p;
            cont=cont+1;
        end
    case 5
        for p=vmin:vstep:vmax
            n=PureSubstanceProperties(fixed,p,'none',s);
            n=n.Get_Gibbs;
            Y(cont)=n.Gibbs_energy;
            X(cont)=p;
            cont=cont+1;
        end
    case 6
        for p=vmin:vstep:vmax
            n=PureSubstanceProperties(fixed,p,'none',s);
            n=n.Get_Cv;
            Y(cont)=n.isochoric_heat_C;
            X(cont)=p;
            cont=cont+1;
        end
    case 7
        for p=vmin:vstep:vmax
            n=PureSubstanceProperties(fixed,p,'none',s);
            n=n.Get_Cp;
            Y(cont)=n.isobaric_heat_C;
            X(cont)=p;
            cont=cont+1;
        end
    case 8
        for p=vmin:vstep:vmax
            n=PureSubstanceProperties(fixed,p,'none',s);
            n=n.Get_compressibility;
            Y(cont)=n.isothermal_compressibility;
            X(cont)=p;
            cont=cont+1;
        end
    case 9
        for p=vmin:vstep:vmax
            n=PureSubstanceProperties(fixed,p,'none',s);
            n=n.Get_w;
            Y(cont)=n.speed_sound;
            X(cont)=p;
            cont=cont+1;
        end
    case 10
        for p=vmin:vstep:vmax
            n=PureSubstanceProperties(fixed,p,'none',s);
            n=n.Get_mi;
            Y(cont)=n.Joule_Thomson_coef;
            X(cont)=p;
            cont=cont+1;
        end
    case 11
        for p=vmin:vstep:vmax
            n=PureSubstanceProperties(fixed,p,'none',s);
            n=n.Get_throttle;
            Y(cont)=n.isot_throttle_coef;
            X(cont)=p;
            cont=cont+1;
        end
    case 12
        for p=vmin:vstep:vmax
            n=PureSubstanceProperties(fixed,p,'none',s);
            n=n.Get_isentropic;
            Y(cont)=n.isentropic_t_p_coef;
            X(cont)=p;
            cont=cont+1;
        end
    case 13
        for p=vmin:vstep:vmax
            n=PureSubstanceProperties(fixed,p,'none',s);
            n=n.Get_second_v;
            Y(cont)=n.second_virial;
            X(cont)=p;
            cont=cont+1;
        end
    case 14
        for p=vmin:vstep:vmax
            n=PureSubstanceProperties(fixed,p,'none',s);
            n=n.Get_third_v;
            Y(cont)=n.third_virial;
            X(cont)=p;
            cont=cont+1;
        end
    end
end
        
plot(X, Y);





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



function FixedValue_Callback(hObject, eventdata, handles)
% hObject    handle to FixedValue (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of FixedValue as text
%        str2double(get(hObject,'String')) returns contents of FixedValue as a double


% --- Executes during object creation, after setting all properties.
function FixedValue_CreateFcn(hObject, eventdata, handles)
% hObject    handle to FixedValue (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in FixedUnit_T.
function FixedUnit_T_Callback(hObject, eventdata, handles)
% hObject    handle to FixedUnit_T (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns FixedUnit_T contents as cell array
%        contents{get(hObject,'Value')} returns selected item from FixedUnit_T


% --- Executes during object creation, after setting all properties.
function FixedUnit_T_CreateFcn(hObject, eventdata, handles)
% hObject    handle to FixedUnit_T (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function VarMin_Callback(hObject, eventdata, handles)
% hObject    handle to VarMin (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of VarMin as text
%        str2double(get(hObject,'String')) returns contents of VarMin as a double


% --- Executes during object creation, after setting all properties.
function VarMin_CreateFcn(hObject, eventdata, handles)
% hObject    handle to VarMin (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in VarUnit_D.
function VarUnit_D_Callback(hObject, eventdata, handles)
% hObject    handle to VarUnit_D (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns VarUnit_D contents as cell array
%        contents{get(hObject,'Value')} returns selected item from VarUnit_D


% --- Executes during object creation, after setting all properties.
function VarUnit_D_CreateFcn(hObject, eventdata, handles)
% hObject    handle to VarUnit_D (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function VarStep_Callback(hObject, eventdata, handles)
% hObject    handle to VarStep (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of VarStep as text
%        str2double(get(hObject,'String')) returns contents of VarStep as a double


% --- Executes during object creation, after setting all properties.
function VarStep_CreateFcn(hObject, eventdata, handles)
% hObject    handle to VarStep (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function VarMax_Callback(hObject, eventdata, handles)
% hObject    handle to VarMax (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of VarMax as text
%        str2double(get(hObject,'String')) returns contents of VarMax as a double


% --- Executes during object creation, after setting all properties.
function VarMax_CreateFcn(hObject, eventdata, handles)
% hObject    handle to VarMax (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in XAxis.
function XAxis_Callback(hObject, eventdata, handles)
% hObject    handle to XAxis (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns XAxis contents as cell array
%        contents{get(hObject,'Value')} returns selected item from XAxis


% --- Executes during object creation, after setting all properties.
function XAxis_CreateFcn(hObject, eventdata, handles)
% hObject    handle to XAxis (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in YAxis.
function YAxis_Callback(hObject, eventdata, handles)
% hObject    handle to YAxis (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns YAxis contents as cell array
%        contents{get(hObject,'Value')} returns selected item from YAxis


% --- Executes during object creation, after setting all properties.
function YAxis_CreateFcn(hObject, eventdata, handles)
% hObject    handle to YAxis (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in IsFixedT.
function IsFixedT_Callback(hObject, eventdata, handles)
% hObject    handle to IsFixedT (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if get(hObject,'Value')==1
    set(handles.IsFixedV,'Value',0);
    set(handles.FixedUnit_T,'Visible','on');
    set(handles.FixedUnit_D,'Visible','off');
    set(handles.VarUnit_T,'Visible','off');
    set(handles.VarUnit_D,'Visible','on');
else
    set(handles.IsFixedV,'Value',1);
end
% Hint: get(hObject,'Value') returns toggle state of IsFixedT


% --- Executes on button press in IsFixedV.
function IsFixedV_Callback(hObject, eventdata, handles)
% hObject    handle to IsFixedV (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if get(hObject,'Value')==1
    set(handles.IsFixedT,'Value',0);
    set(handles.FixedUnit_T,'Visible','off');
    set(handles.FixedUnit_D,'Visible','on');
    set(handles.VarUnit_T,'Visible','on');
    set(handles.VarUnit_D,'Visible','off');
else
    set(handles.IsFixedT,'Value',1);
end
% Hint: get(hObject,'Value') returns toggle state of IsFixedV


% --- Executes on button press in Clear.
function Clear_Callback(hObject, eventdata, handles)
% hObject    handle to Clear (see GCBO)
clear handles.Graphic
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on selection change in VarUnit_T.
function VarUnit_T_Callback(hObject, eventdata, handles)
% hObject    handle to VarUnit_T (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns VarUnit_T contents as cell array
%        contents{get(hObject,'Value')} returns selected item from VarUnit_T


% --- Executes during object creation, after setting all properties.
function VarUnit_T_CreateFcn(hObject, eventdata, handles)
% hObject    handle to VarUnit_T (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in FixedUnit_D.
function FixedUnit_D_Callback(hObject, eventdata, handles)
% hObject    handle to FixedUnit_D (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns FixedUnit_D contents as cell array
%        contents{get(hObject,'Value')} returns selected item from FixedUnit_D


% --- Executes during object creation, after setting all properties.
function FixedUnit_D_CreateFcn(hObject, eventdata, handles)
% hObject    handle to FixedUnit_D (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
