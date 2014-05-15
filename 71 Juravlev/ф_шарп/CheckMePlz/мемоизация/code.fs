let fieldSearching =  "vlad vladeet vladivostokom".ToCharArray() |> Array.toList // ������������� � ������� ��������, ����� � ������ ��������
let template = "vlad".ToCharArray() |> Array.toList // ����������


// as = ������������, ����� ���� �������� ������� ������ ��� �������.
// :: = ������������ � �������������� � �������� ��� ��������� ������ ������.
// :: = ������� ������. ������� ����� ����� �������������� � ������ ������ �����.
// |> = �������� ��������� ����� ����� � ������� ������ ����� (�������� ������� ������).
// -> = ������ ��������� 
// -> = ������������ � ���������� ������������

let rec simple = function
    | _, [] -> 1 // ������ �������� ������ ������� ����, ������ 1
    | [], _ -> 0 // ������ �������� ������ ��� ����  ����, ������ 0
    | fieldSearchingHead  :: fieldSearchingTail as fieldSearching,  (templateHead :: templateTail  as template) -> // ������� �� ����� � ������ ������ ��� ���� , ���������� � ��������
        if fieldSearchingHead = templateHead  then // ������� �������, ��������� ���������
            simple (fieldSearchingTail , templateTail) + simple (fieldSearchingTail , template)
        else
            simple (fieldSearchingTail , template)

let res = simple (fieldSearching, template)
printfn "%A" res

// ����� � ��� ��� ���� � ���� ����������� ������ �� ��������
let memoization fieldSearchingIn templateIn = 
    let memo = new System.Collections.Generic.Dictionary<(list<char> * list<char>), bigint> () // ������������ ��������� ������ � ��������.
    let rec insideFun fieldSearchingIn2 templateIn2 = 
        if memo.ContainsKey (fieldSearchingIn2 , templateIn2) then // ����������, ���������� �� ��������� ���� � ������� Dictionary(TKey, TValue).
            memo.[(fieldSearchingIn2 , templateIn2)]
        else
            let slot = 
                match (fieldSearchingIn2 , templateIn2) with
                | _, [] -> 1I
                | [], _ -> 0I
                | fieldHead :: fieldTail, templateHead :: templateTail -> 
                    if fieldHead = templateHead  then
                        insideFun fieldTail templateTail + insideFun fieldTail templateIn2 // ��������� ������ � ����� ��������� ����������
                    else
                        insideFun fieldTail templateIn2 // �� ������� - ��������� ���������
            memo.Add ((fieldSearchingIn2 , templateIn2), slot)
            slot 
    insideFun fieldSearchingIn templateIn

let res2 = memoization fieldSearching template
printfn "%A" res2