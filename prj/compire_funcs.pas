unit compire_funcs;
    
interface
uses types;
function scholarship_sort(a, b: Student):boolean;
function group_and_date_sort(a, b: Student):boolean;

implementation

function scholarship_sort(a, b: Student):boolean;
begin
    result := a.scholarship < b.scholarship;
end;

function group_and_date_sort(a, b: Student):boolean;
begin
    result := a.grp = b.grp ? a.year < b.year : a.grp < b.grp;
end;





end.