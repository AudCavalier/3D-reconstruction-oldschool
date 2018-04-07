#include <iostream>
#include <math.h>
#include <octave/oct.h>
#include <fstream>

/*
*/
int main(){
	Matrix S=Matrix(12, 1); //Vector de Soluciones (Ui, Vi)
	Matrix S_2=Matrix(12, 1); //Para la segunda matriz
	Matrix L=Matrix(12, 11);  //Matriz de ecuaciones IMAGEN IZQUIERDA
	Matrix L_2=Matrix(12, 11); //Matriz de ecuaciones IMAGEN DERECHA
	Matrix V=Matrix(11, 1); //Vector de Variables P's
	Matrix V_2=Matrix(11, 1);
	Matrix P=Matrix(3,4); //Matriz de proyeccion 1
	Matrix P_2=Matrix(3,4); //Matriz de proyeccion 2
	double X, Y, Z, T; //Valores de X, Y, Z y T
	float u1, v1, u2, v2, u3, v3, u4, v4, u5, v5, u6, v6;
	int tempi=0;
	
	//Llenando la matriz L LIKE A BOSS
	L(0,0)=0; L(0,1)=40; L(0,2)=80; L(0,3)=1; 
	L(0,4)=0; L(0,5)=0; L(0,6)=0; L(0,7)=0; 
	u1=803.0; v1=400.0;
	L(0,8)=-u1*L(0,0); L(0,9)=-u1*L(0,1); L(0,10)=-u1*L(0,2);
	//Segunda fila
	L(1,0)=0; L(1,1)=0; L(1,2)=0; L(1,3)=0; 
	L(1,4)=0; L(1,5)=40; L(1,6)=80; L(1,7)=1; 
	L(1,8)=-v1*L(1,4); L(1,9)=-v1*L(1,5); L(1,10)=-v1*L(1,6);
	//Tercera fila
	L(2,0)=0; L(2,1)=60; L(2,2)=40; L(2,3)=1; 
	L(2,4)=0; L(2,5)=0; L(2,6)=0; L(2,7)=0; 
	u2=748.0; v2=344.0;
	L(2,8)=-u2*L(2,0); L(2,9)=-u2*L(2,1); L(2,10)=-u2*L(2,2);
	//Cuarta fila
	L(3,0)=0; L(3,1)=0; L(3,2)=0; L(3,3)=0; 
	L(3,4)=0; L(3,5)=60; L(3,6)=40; L(3,7)=1; 
	L(3,8)=-v2*L(3,4); L(3,9)=-v2*L(3,5); L(3,10)=-v2*L(3,6);
	//Quinta fila
	L(4,0)=0; L(4,1)=120; L(4,2)=120; L(4,3)=1; 
	L(4,4)=0; L(4,5)=0; L(4,6)=0; L(4,7)=0; 
	u3=875.0; v3=254.0;
	L(4,8)=-u3*L(4,0); L(4,9)=-u3*L(4,1); L(4,10)=-u3*L(4,2);
	//Sexta fila
	L(5,0)=0; L(5,1)=0; L(5,2)=0; L(5,3)=0; 
	L(5,4)=0; L(5,5)=120; L(5,6)=120; L(5,7)=1; 
	L(5,8)=-v3*L(5,4); L(5,9)=-v3*L(5,5); L(5,10)=-v3*L(5,6);
	//Septima fila
	L(6,0)=-40; L(6,1)=120; L(6,2)=0; L(6,3)=1; 
	L(6,4)=0; L(6,5)=0; L(6,6)=0; L(6,7)=0; 
	u4=636.0; v4=233.0;
	L(6,8)=-u4*L(6,0); L(6,9)=-u4*L(6,1); L(6,10)=-u4*L(6,2);
	//Octava fila
	L(7,0)=0; L(7,1)=0; L(7,2)=0; L(7,3)=0; 
	L(7,4)=-40; L(7,5)=120; L(7,6)=0; L(7,7)=1; 
	L(7,8)=-v4*L(7,4); L(7,9)=-v4*L(7,5); L(7,10)=-v4*L(7,6);
	//Novena fila
	L(8,0)=-120; L(8,1)=100; L(8,2)=0; L(8,3)=1; 
	L(8,4)=0; L(8,5)=0; L(8,6)=0; L(8,7)=0; 
	u5=500.0; v5=300.0;
	L(8,8)=-u5*L(8,0); L(8,9)=-u5*L(8,1); L(8,10)=-u5*L(8,2);
	//Decima fila
	L(9,0)=0; L(9,1)=0; L(9,2)=0; L(9,3)=0; 
	L(9,4)=-120; L(9,5)=100; L(9,6)=0; L(9,7)=1; 
	L(9,8)=-v5*L(9,4); L(9,9)=-v5*L(9,5); L(9,10)=-v5*L(9,6);
	//Decimoprimera fila
	L(10,0)=-100; L(10,1)=40; L(10,2)=0; L(10,3)=1; 
	L(10,4)=0; L(10,5)=0; L(10,6)=0; L(10,7)=0; 
	u6=580.0; v6=397.0;
	L(10,8)=-u6*L(10,0); L(10,9)=-u6*L(10,1); L(10,10)=-u6*L(10,2);
	//Decimosegunda fila
	L(11,0)=0; L(11,1)=0; L(11,2)=0; L(11,3)=0; 
	L(11,4)=-100; L(11,5)=40; L(11,6)=0; L(11,7)=1; 
	L(11,8)=-v6*L(11,4); L(11,9)=-v6*L(11,5); L(11,10)=-v6*L(11,6);
	
	S(0,0)=u1; S(1,0)=v1; S(2,0)=u2; S(3,0)=v2;
	S(4,0)=u3; S(5,0)=v3; S(6,0)=u4; S(7,0)=v4;
	S(8,0)=u5; S(9,0)=v5; S(10,0)=u6; S(11,0)=v6;
	
	V=L.solve(S);
	for(int i=0; i<3; i++){
		for(int j=0; j<4; j++){
			P(i,j)=V(tempi,0);
			tempi++;
		}
	}
	tempi=0;
	P(2,3)=1;

	//SE HACE EL MISMO CHORIZO PERO PARA LA SEGUNDA MATRIZ DE PROYECCION
	
	//Llenando la matriz L_2
	L_2(0,0)=0; L_2(0,1)=20; L_2(0,2)=80; L_2(0,3)=1; 
	L_2(0,4)=0; L_2(0,5)=0; L_2(0,6)=0; L_2(0,7)=0; 
	u1=802.0; v1=437.0;
	L_2(0,8)=-u1*L_2(0,0); L_2(0,9)=-u1*L_2(0,1); L_2(0,10)=-u1*L_2(0,2);
	//Segunda fila
	L_2(1,0)=0; L_2(1,1)=0; L_2(1,2)=0; L_2(1,3)=0; 
	L_2(1,4)=0; L_2(1,5)=20; L_2(1,6)=80; L_2(1,7)=1; 
	L_2(1,8)=-v1*L_2(1,4); L_2(1,9)=-v1*L_2(1,5); L_2(1,10)=-v1*L_2(1,6);
	//Tercera fila
	L_2(2,0)=0; L_2(2,1)=80; L_2(2,2)=120; L_2(2,3)=1; 
	L_2(2,4)=0; L_2(2,5)=0; L_2(2,6)=0; L_2(2,7)=0; 
	u2=871.0; v2=340.0;
	L_2(2,8)=-u2*L_2(2,0); L_2(2,9)=-u2*L_2(2,1); L_2(2,10)=-u2*L_2(2,2);
	//Cuarta fila
	L_2(3,0)=0; L_2(3,1)=0; L_2(3,2)=0; L_2(3,3)=0; 
	L_2(3,4)=0; L_2(3,5)=80; L_2(3,6)=120; L_2(3,7)=1; 
	L_2(3,8)=-v2*L_2(3,4); L_2(3,9)=-v2*L_2(3,5); L_2(3,10)=-v2*L_2(3,6);
	//Quinta fila
	L_2(4,0)=0; L_2(4,1)=120; L_2(4,2)=40; L_2(4,3)=1; 
	L_2(4,4)=0; L_2(4,5)=0; L_2(4,6)=0; L_2(4,7)=0; 
	u3=749.0; v3=230.0;
	L_2(4,8)=-u3*L_2(4,0); L_2(4,9)=-u3*L_2(4,1); L_2(4,10)=-u3*L_2(4,2);
	//Sexta fila
	L_2(5,0)=0; L_2(5,1)=0; L_2(5,2)=0; L_2(5,3)=0; 
	L_2(5,4)=0; L_2(5,5)=120; L_2(5,6)=40; L_2(5,7)=1; 
	L_2(5,8)=-v3*L_2(5,4); L_2(5,9)=-v3*L_2(5,5); L_2(5,10)=-v3*L_2(5,6);
	//Septima fila
	L_2(6,0)=-40; L_2(6,1)=140; L_2(6,2)=0; L_2(6,3)=1; 
	L_2(6,4)=0; L_2(6,5)=0; L_2(6,6)=0; L_2(6,7)=0; 
	u4=635.0; v4=192.0;
	L_2(6,8)=-u4*L_2(6,0); L_2(6,9)=-u4*L_2(6,1); L_2(6,10)=-u4*L_2(6,2);
	//Octava fila
	L_2(7,0)=0; L_2(7,1)=0; L_2(7,2)=0; L_2(7,3)=0; 
	L_2(7,4)=-40; L_2(7,5)=140; L_2(7,6)=0; L_2(7,7)=1; 
	L_2(7,8)=-v4*L_2(7,4); L_2(7,9)=-v4*L_2(7,5); L_2(7,10)=-v4*L_2(7,6);
	//Novena fila
	L_2(8,0)=-20; L_2(8,1)=80; L_2(8,2)=0; L_2(8,3)=1; 
	L_2(8,4)=0; L_2(8,5)=0; L_2(8,6)=0; L_2(8,7)=0; 
	u5=669.0; v5=300.0;
	L_2(8,8)=-u5*L_2(8,0); L_2(8,9)=-u5*L_2(8,1); L_2(8,10)=-u5*L_2(8,2);
	//Decima fila
	L_2(9,0)=0; L_2(9,1)=0; L_2(9,2)=0; L_2(9,3)=0; 
	L_2(9,4)=-20; L_2(9,5)=80; L_2(9,6)=0; L_2(9,7)=1; 
	L_2(9,8)=-v5*L_2(9,4); L_2(9,9)=-v5*L_2(9,5); L_2(9,10)=-v5*L_2(9,6);
	//Decimoprimera fila
	L_2(10,0)=-120; L_2(10,1)=60; L_2(10,2)=0; L_2(10,3)=1; 
	L_2(10,4)=0; L_2(10,5)=0; L_2(10,6)=0; L_2(10,7)=0; 
	u6=507.0; v6=380.0;
	L_2(10,8)=-u6*L_2(10,0); L_2(10,9)=-u6*L_2(10,1); L_2(10,10)=-u6*L_2(10,2);
	//Decimosegunda fila
	L_2(11,0)=0; L_2(11,1)=0; L_2(11,2)=0; L_2(11,3)=0; 
	L_2(11,4)=-120; L_2(11,5)=60; L_2(11,6)=0; L_2(11,7)=1; 
	L_2(11,8)=-v6*L_2(11,4); L_2(11,9)=-v6*L_2(11,5); L_2(11,10)=-v6*L_2(11,6);
	
	S_2(0,0)=u1; S_2(1,0)=v1; S_2(2,0)=u2; S_2(3,0)=v2;
	S_2(4,0)=u3; S_2(5,0)=v3; S_2(6,0)=u4; S_2(7,0)=v4;
	S_2(8,0)=u5; S_2(9,0)=v5; S_2(10,0)=u6; S_2(11,0)=v6;
	
	V_2=L_2.solve(S_2);
	for(int i=0; i<3; i++){
		for(int j=0; j<4; j++){
			P_2(i,j)=V_2(tempi,0);
			tempi++;
		}
	}
	tempi=0;
	P_2(2,3)=1;

	//Debugsitos bonitillos
	//std::cout << "MATRIZ DE PROYECCION 1:" << std::endl;
	//std::cout << P;
	//std::cout << "MATRIZ DE PROYECCION 2:" << std::endl;
	//std::cout << P_2;
	
	Matrix C=Matrix(4, 1); //Matriz de centroides
	Matrix p234 = Matrix(3,3);
	p234(0,0)=P(0,1); p234(0,1)=P(0,2); p234(0,2)=P(0,3);
	p234(1,0)=P(1,1); p234(1,1)=P(1,2); p234(1,2)=P(1,3);
	p234(2,0)=P(2,1); p234(2,1)=P(2,2); p234(2,2)=P(2,3);
	Matrix p134 = Matrix(3,3);
	p134(0,0)=P(0,0); p134(0,1)=P(0,2); p134(0,2)=P(0,3);
	p134(1,0)=P(1,0); p134(1,1)=P(1,2); p134(1,2)=P(1,3);
	p134(2,0)=P(2,0); p134(2,1)=P(2,2); p134(2,2)=P(2,3);
	Matrix p124 = Matrix(3,3);
	p124(0,0)=P(0,0); p124(0,1)=P(0,1); p124(0,2)=P(0,3);
	p124(1,0)=P(1,0); p124(1,1)=P(1,1); p124(1,2)=P(1,3);
	p124(2,0)=P(2,0); p124(2,1)=P(2,1); p124(2,2)=P(2,3);
	Matrix p123 = Matrix(3,3);
	p123(0,0)=P(0,0); p123(0,1)=P(0,1); p123(0,2)=P(0,2);
	p123(1,0)=P(1,0); p123(1,1)=P(1,1); p123(1,2)=P(1,2);
	p123(2,0)=P(2,0); p123(2,1)=P(2,1); p123(2,2)=P(2,2);
	//X=DET(p234);
	X=p234(0,0)*((p234(1,1)*p234(2,2))-(p234(1,2)*p234(2,1)))-p234(0,1)*((p234(1,0)*p234(2,2))-(p234(1,2)*p234(2,0)))+p234(0,2)*((p234(1,0)*p234(2,1))-(p234(1,1)*p234(2,0)));
	//Y=-DET(p134);
	Y=-(p134(0,0)*((p134(1,1)*p134(2,2))-(p134(1,2)*p134(2,1)))-p134(0,1)*((p134(1,0)*p134(2,2))-(p134(1,2)*p134(2,0)))+p134(0,2)*((p134(1,0)*p134(2,1))-(p134(1,1)*p134(2,0))));
	//Z=DET(p124);
	Z=p124(0,0)*((p124(1,1)*p124(2,2))-(p124(1,2)*p124(2,1)))-p124(0,1)*((p124(1,0)*p124(2,2))-(p124(1,2)*p124(2,0)))+p124(0,2)*((p124(1,0)*p124(2,1))-(p124(1,1)*p124(2,0)));
	//T=-DET(p123);
	T=-(p123(0,0)*((p123(1,1)*p123(2,2))-(p123(1,2)*p123(2,1)))-p123(0,1)*((p123(1,0)*p123(2,2))-(p123(1,2)*p123(2,0)))+p123(0,2)*((p123(1,0)*p123(2,1))-(p123(1,1)*p123(2,0))));
	C(0,0)=X; C(1,0)=Y; C(2,0)=Z; C(3,0)=T;
	//TODO: MATRIZ DE ROTACION Qx, Qy, Qz, Matriz K y Matriz M que es K*Qz*Qy*Qx
	Matrix M=Matrix(3,3);
	Matrix MPrime=Matrix(3,3);
	Matrix K=Matrix(3,3);
	Matrix R=Matrix(3,3);
	Matrix Qx=Matrix(3,3);
	Matrix Qy=Matrix(3,3);
	Matrix Qz=Matrix(3,3);
	//Definicion de M, EN PRINCIPIO
	M(0,0)=P(0,0); M(0,1)=P(0,1); M(0,2)=P(0,2);
	M(1,0)=P(1,0); M(1,1)=P(1,1); M(1,2)=P(1,2);
	M(2,0)=P(2,0); M(2,1)=P(2,1); M(2,2)=P(2,2);
	double cosx, sinx, cosy, siny, cosz, sinz;
	//Valores cosx y sinx
	cosx=-M(2,2)/(sqrt(pow(M(2,1),2)+pow(M(2,2),2)));
	sinx=M(2,1)/(sqrt(pow(M(2,1),2)+pow(M(2,2),2)));
	//Definicion de Qx
	Qx(0,0)=1; Qx(0,1)=0; Qx(0,2)=0;
	Qx(1,0)=0; Qx(1,1)=cosx; Qx(1,2)=-sinx;
	Qx(2,0)=0; Qx(2,1)=sinx; Qx(2,2)=cosx;
	//MULTIPLICAMOS M * Qx
	MPrime=M*Qx; //Decidí dejar M intacta, por que creo la ocuparé
	/*std::cout << "Matriz QX" << std::endl;
	std::cout << Qx;
	std::cout << "Matriz M" << std::endl;
	std::cout << MPrime;
	std::cout << M(2,0) << "*" << Qx(0,1) << "+" << M(2,1) << "*" << Qx(1,1) << "+" << M(2,2) << "*" << Qx(2,1) << " = ";
	double temp = M(2,0)*Qx(0,1)+M(2,1)*Qx(1,1)+M(2,2)*Qx(2,1);
	std::cout << temp << std::endl;
	*/
	//Valores cosy y siny
	cosy=MPrime(2,2)/sqrt(pow(MPrime(2,0),2)+pow(MPrime(2,2),2));
	siny=MPrime(2,0)/sqrt(pow(MPrime(2,0),2)+pow(MPrime(2,2),2));
	//Definicion de Qy
	Qy(0,0)=cosy; Qy(0,1)=0; Qy(0,2)=siny;
	Qy(1,0)=0; Qy(1,1)=1; Qy(1,2)=0;
	Qy(2,0)=-siny; Qy(2,1)=0; Qy(2,2)=cosy;
	//MQx * Qy
	MPrime=MPrime*Qy;
	//Valores cosz y sinz
	cosz=MPrime(1,1)/sqrt(pow(MPrime(1,0),2)+pow(MPrime(1,1),2));
	sinz=-MPrime(1,0)/sqrt(pow(MPrime(1,0),2)+pow(MPrime(1,1),2)); //REVISAR EL VALOR DEL NUMERADOR
	//Definicion de Qz
	Qz(0,0)=cosz; Qz(0,1)=-sinz; Qz(0,2)=0;
	Qz(1,0)=sinz; Qz(1,1)=cosz; Qz(1,2)=0;
	Qz(2,0)=0; Qz(2,1)=0; Qz(2,2)=1;
	R=Qx*Qy*Qz;
	K=M*Qx*Qy*Qz;
	//Más debugs, los dejaré para que se vea bonito el programa
	std::cout << "Matriz K" << std::endl;
	std::cout << K;
	std::cout << "Matriz R" << std::endl;
	std::cout << R;
	std::cout << "Centroides" <<std::endl;
	std::cout << C;
	
	/* ESTO YA LO REVISÉ CON PHOTOSHOP, SI FUNCIONÓ
 	double pointx=-60, pointy=80, pointz=0; //Si esto funciona, dado un punto X, Y, Z en coordenadas reales, me debe dar las coordenadas en pixeles correctas
 	double up, vp; //Veamos si es cierto
 	Matrix solvect=Matrix(3,1);
 	Matrix realvect=Matrix(4,1);
 	realvect(0,0)=pointx; realvect(1,0)=pointy; realvect(2,0)=pointz; realvect(3,0)=1;
 	solvect=P*realvect;
 	up=solvect(0,0)/solvect(2,0);
 	vp=solvect(1,0)/solvect(2,0);
 	std::cout << "PUNTO DADO" << std::endl;
 	std::cout<<realvect;
 	std::cout << "PUNTO EN PIXELES" << std::endl;
 	std::cout << up << " , " << vp << std::endl;*/
 	//HORA DE HACER LA RECONSTRUCCIÓN 3D
 	/*BUSCAMOS U', V', T' de los puntos
	U1,1=X*P00_1+Y*P01_1+Z*P02_1+P03_1
	V1,1=X*P10_1+.......
	T1,1=...............+Z*P22_1+P23_1
 	PERO.... YA TENEMOS LOS PIXELES -> U1=XP00_1+YP01_1....../XP20_1+YP21_1+ZP22_1+1
 	A VER SI SIRVE ESTA COSA
 	*/

 	//EXTRAYENDO LOS PUNTOS A RECONSTRUIR
 	double ul1, ul2, ul3, ul4, vl1, vl2, vl3, vl4; //U's y V's de la imagen Izquierda, considerando 4 puntos
 	double ur1, ur2, ur3, ur4, vr1, vr2, vr3, vr4; //U's y V's de la imagen Derecha, igual 4 puntos
 	ul1=655.0; vl1=380.0; ul2=657.0; vl2=678.0; ul3=527.0; vl3=585.0; ul4=815.0; vl4=584.0;
 	ur1=474.0; vr1=378.0; ur2=468.0; vr2=677.0; ur3=363.0; vr3=585.0; ur4=649.0; vr4=579.0;
 	//X, Y, Z que buscamos
 	//Como utilizaremos 4 puntos, haremos 4 matrices para calcular los puntos a graficar
 	Matrix Points1=Matrix(3,1); 
 	Matrix Points2=Matrix(3,1); 
 	Matrix Points3=Matrix(3,1);
 	Matrix Points4=Matrix(3,1);
 	Matrix Lprime=Matrix(4,3); //L1, L2, L3
 	Matrix Sprime1=Matrix(4,1); //S= U_n-P_rs
 	Lprime(0,0)=P(0,0)-ul1*P(2,0); Lprime(0,1)=P(0,1)-ul1*P(2,1); Lprime(0,2)=P(0,2)-ul1*P(2,2); //U IMG1
 	Lprime(1,0)=P(1,0)-vl1*P(2,0); Lprime(1,1)=P(1,1)-vl1*P(2,1); Lprime(1,2)=P(1,2)-vl1*P(2,2); //V IMG1
 	Lprime(2,0)=P_2(0,0)-ur1*P_2(2,0); Lprime(2,1)=P_2(0,1)-ur1*P_2(2,1); Lprime(2,2)=P_2(0,2)-ur1*P_2(2,2); //U IMG2
 	Lprime(3,0)=P_2(1,0)-vr1*P_2(2,0); Lprime(3,1)=P_2(1,1)-vr1*P_2(2,1); Lprime(3,2)=P_2(1,2)-vr1*P_2(2,2); //V IMG2
 	Sprime1(0,0)=ul1-P(0,3); Sprime1(1,0)=vl1-P(1,3); Sprime1(2,0)=ur1-P_2(0,3); Sprime1(3,0)=vr1-P_2(1,3); //Vector S correspondiente al primer punto
 	Points1=Lprime.solve(Sprime1);
 	//PUNTO 2
 	Lprime(0,0)=P(0,0)-ul2*P(2,0); Lprime(0,1)=P(0,1)-ul2*P(2,1); Lprime(0,2)=P(0,2)-ul2*P(2,2); //U IMG1
 	Lprime(1,0)=P(1,0)-vl2*P(2,0); Lprime(1,1)=P(1,1)-vl2*P(2,1); Lprime(1,2)=P(1,2)-vl2*P(2,2); //V IMG1
 	Lprime(2,0)=P_2(0,0)-ur2*P_2(2,0); Lprime(2,1)=P_2(0,1)-ur2*P_2(2,1); Lprime(2,2)=P_2(0,2)-ur2*P_2(2,2); //U IMG2
 	Lprime(3,0)=P_2(1,0)-vr2*P_2(2,0); Lprime(3,1)=P_2(1,1)-vr2*P_2(2,1); Lprime(3,2)=P_2(1,2)-vr2*P_2(2,2); //V IMG2
 	Sprime1(0,0)=ul2-P(0,3); Sprime1(1,0)=vl2-P(1,3); Sprime1(2,0)=ur2-P_2(0,3); Sprime1(3,0)=vr2-P_2(1,3); //Vector S correspondiente al primer punto
 	Points2=Lprime.solve(Sprime1);
 	//PUNTO 3
 	Lprime(0,0)=P(0,0)-ul3*P(2,0); Lprime(0,1)=P(0,1)-ul3*P(2,1); Lprime(0,2)=P(0,2)-ul3*P(2,2); //U IMG1
 	Lprime(1,0)=P(1,0)-vl3*P(2,0); Lprime(1,1)=P(1,1)-vl3*P(2,1); Lprime(1,2)=P(1,2)-vl3*P(2,2); //V IMG1
 	Lprime(2,0)=P_2(0,0)-ur3*P_2(2,0); Lprime(2,1)=P_2(0,1)-ur3*P_2(2,1); Lprime(2,2)=P_2(0,2)-ur3*P_2(2,2); //U IMG2
 	Lprime(3,0)=P_2(1,0)-vr3*P_2(2,0); Lprime(3,1)=P_2(1,1)-vr3*P_2(2,1); Lprime(3,2)=P_2(1,2)-vr3*P_2(2,2); //V IMG2
 	Sprime1(0,0)=ul3-P(0,3); Sprime1(1,0)=vl3-P(1,3); Sprime1(2,0)=ur3-P_2(0,3); Sprime1(3,0)=vr3-P_2(1,3); //Vector S correspondiente al primer punto
 	Points3=Lprime.solve(Sprime1);
 	//PUNTO 4
 	Lprime(0,0)=P(0,0)-ul4*P(2,0); Lprime(0,1)=P(0,1)-ul4*P(2,1); Lprime(0,2)=P(0,2)-ul4*P(2,2); //U IMG1
 	Lprime(1,0)=P(1,0)-vl4*P(2,0); Lprime(1,1)=P(1,1)-vl4*P(2,1); Lprime(1,2)=P(1,2)-vl4*P(2,2); //V IMG1
 	Lprime(2,0)=P_2(0,0)-ur4*P_2(2,0); Lprime(2,1)=P_2(0,1)-ur4*P_2(2,1); Lprime(2,2)=P_2(0,2)-ur4*P_2(2,2); //U IMG2
 	Lprime(3,0)=P_2(1,0)-vr4*P_2(2,0); Lprime(3,1)=P_2(1,1)-vr4*P_2(2,1); Lprime(3,2)=P_2(1,2)-vr4*P_2(2,2); //V IMG2
 	Sprime1(0,0)=ul4-P(0,3); Sprime1(1,0)=vl4-P(1,3); Sprime1(2,0)=ur4-P_2(0,3); Sprime1(3,0)=vr4-P_2(1,3); //Vector S correspondiente al primer punto
 	Points4=Lprime.solve(Sprime1);
 	//Llenamos el archivo con los puntos para graficar

 	std::ofstream plotpoints("Puntos.dat");
 	plotpoints<<"# X               Y               Z\n";
 	plotpoints<<Points1(2,0) << "     " << Points1(0,0) << "     " << Points1(1,0) << "\n";
 	plotpoints<<Points3(2,0) << "     " << Points3(0,0) << "     " << Points3(1,0) << "\n";
 	plotpoints<<Points2(2,0) << "     " << Points2(0,0) << "     " << Points2(1,0) << "\n";
 	plotpoints<<Points1(2,0) << "     " << Points1(0,0) << "     " << Points1(1,0) << "\n";
 	plotpoints<<Points4(2,0) << "     " << Points4(0,0) << "     " << Points4(1,0) << "\n";
 	plotpoints<<Points2(2,0) << "     " << Points2(0,0) << "     " << Points2(1,0) << "\n";
 	
 	plotpoints.close();
 	std::cout << "Archivo creado con exito, proceder a graficar con gnuplot, pgfplots o el programa de plotteo preferido" << std::endl;
	return 0; 
}