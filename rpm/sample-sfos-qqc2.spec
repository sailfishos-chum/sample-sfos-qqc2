Name:       sample-sfos-qqc2
Summary:    Sample QtQuick Controls 2 application for SailfishOS
Version:    1.0
Release:    1
License:    BSD
URL:        https://github.com/sailfishos-chum/sample-sfos-qqc2
Source0:    %{name}-%{version}.tar.bz2
Requires:       qt-runner
Requires:       opt-qt5-qtquickcontrols2 >= 5.15.8
BuildRequires:  opt-qt5-qtdeclarative-devel >= 5.15.8
BuildRequires:  opt-qt5-qtquickcontrols2-devel >= 5.15.8
BuildRequires:  desktop-file-utils

%description
Short description of my SailfishOS Application

%prep
%autosetup -n %{name}-%{version}/src

%build
%{opt_qmake_qt5}
%make_build

%install
rm -rf %{buildroot}
%qmake5_install

desktop-file-install --delete-original       \
  --dir %{buildroot}%{_datadir}/applications             \
   %{buildroot}%{_datadir}/applications/*.desktop

%files
%defattr(-,root,root,-)
/opt/%{name}/bin/%{name}
%{_datadir}/applications/%{name}.desktop
%{_datadir}/icons/hicolor/86x86/apps/%{name}.png