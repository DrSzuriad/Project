.code
const qword 1.0
const1 qword -1.0
asmobliczvx proc
movsd xmm0,[const]
divsd xmm0,qword ptr[rcx] ;1/cd
movsd xmm1,qword ptr[rcx+10h] 
mulsd xmm1,qword ptr[rcx+18h];cw*vw
movsd xmm2, qword ptr[rcx]
mulsd xmm2, qword ptr[rcx+20h];cd*vx
addsd xmm2,xmm1 ;cw*vw+cd*vx
mulsd xmm2, qword ptr[rcx+8h]; (cw*vw+cd*vx) * e
subsd xmm2,xmm1; (cw*vw+cd*vx) * e -cw * vw
mulsd xmm0,xmm2; (1/cd)* ((cw*vw+cd*vx) * e -cw * vw)
ret
asmobliczvx endp
;########################
asmobliczvy proc
movsd xmm0,[const]
movsd xmm1,qword ptr[rcx];cd
divsd xmm0,xmm1 ;1/cd
mulsd xmm1,qword ptr[rcx+10h];cd*vy
movsd xmm2,qword ptr[rcx+8h]
mulsd xmm2,qword ptr[rcx+18h];m*g
addsd xmm1,xmm2;cd*vy+m*g
mulsd xmm2,xmm0;(m * g) / cd
mulsd xmm0,qword ptr[rcx+20h];1/cd * e
mulsd xmm0,xmm1; 1/cd * e*(cd*vy+m*g)
subsd xmm0,xmm2;1/cd * e*(cd*vy+m*g)-(m * g) / cd
ret
asmobliczvy endp
;##########################
asmobliczsx proc
movsd xmm0,qword ptr[rcx];m
divsd xmm0,qword ptr[rcx+8h]; m/cd
movsd xmm1,qword ptr[rcx+20h];cw
mulsd xmm1,qword ptr[rcx+28h];cw*vw
divsd xmm1,qword ptr[rcx+8h]; cw*vw/cd
mulsd xmm1,[const1];-cw*vw/cd
movsd xmm2,qword ptr[rcx+18h];t
mulsd xmm2,xmm1;-cw*vw*t/cd
subsd xmm1,qword ptr[rcx+30h];-cw*vw/cd-vx
mulsd xmm1,xmm0;(-cw*cw/cd-vx)*(m/cd)
movsd xmm0,qword ptr[rcx+10h];e
mulsd xmm0,xmm1;(-cw*cw/cd-vx)*(m/cd)*e
addsd xmm0,xmm2;(-cw*cw/cd-vx)*(m/cd)*e + (-cw*vw*t/cd)
subsd xmm0,xmm1;(-cw*cw/cd-vx)*(m/cd)*e + (-cw*vw*t/cd) - (-cw*cw/cd-vx)*(m/cd)
addsd xmm0,qword ptr[rcx+38h];(-cw*cw/cd-vx)*(m/cd)*e + (-cw*vw*t/cd) - (-cw*cw/cd-vx)*(m/cd) +sx
ret
asmobliczsx endp
;########################33
asmobliczsy proc
movsd xmm1,qword ptr[rcx+8h]
divsd xmm1,qword ptr[rcx+20h];m/cd
movsd xmm2,qword ptr[rcx+10h]
mulsd xmm2,xmm1;m*g/cd
movsd xmm3,qword ptr[rcx+30h]
mulsd xmm3,xmm2;m*g*t/cd
addsd xmm2,qword ptr[rcx];m*g/cd+vy
mulsd xmm1,xmm2;(m/cd)*(m*g/cd+vy)
movsd xmm0,qword ptr[rcx+28h]
mulsd xmm0,xmm1;(m/cd)*(m*g/cd+vy)*e
addsd xmm0,qword ptr[rcx+18h];sy + (m/cd)*(m*g/cd+vy)*e
addsd xmm0,xmm3;sy + (m/cd)*(m*g/cd+vy)*e + m*g*t/cd
subsd xmm0,xmm1;sy + (m/cd)*(m*g/cd+vy)*e + (m*g*t/cd)-(m/cd)*(m*g/cd+vy)
ret
asmobliczsy endp
end