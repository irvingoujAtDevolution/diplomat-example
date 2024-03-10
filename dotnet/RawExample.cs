// <auto-generated/> by Diplomat

#pragma warning disable 0105
using System;
using System.Runtime.InteropServices;

using Interop.Diplomat;
#pragma warning restore 0105

namespace Interop.Raw;

#nullable enable

[StructLayout(LayoutKind.Sequential)]
public partial struct Example
{
    private const string NativeLib = "rust";

    [DllImport(NativeLib, CallingConvention = CallingConvention.Cdecl, EntryPoint = "Example_new", ExactSpelling = true)]
    public static unsafe extern Example* New();

    [DllImport(NativeLib, CallingConvention = CallingConvention.Cdecl, EntryPoint = "Example_do_something", ExactSpelling = true)]
    public static unsafe extern void DoSomething(Example* self, byte* bytes, nuint bytesSz);

    [DllImport(NativeLib, CallingConvention = CallingConvention.Cdecl, EntryPoint = "Example_destroy", ExactSpelling = true)]
    public static unsafe extern void Destroy(Example* self);
}