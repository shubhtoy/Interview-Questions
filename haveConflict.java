class Solution {
    public boolean haveConflict(String[] event1, String[] event2) {
        int e1_start_hr = Integer.parseInt(event1[0].substring(0, 2));
        int e1_start_min = Integer.parseInt(event1[0].substring(3, 5));
        int e2_start_hr = Integer.parseInt(event2[0].substring(0, 2));
        int e2_start_min = Integer.parseInt(event2[0].substring(3, 5));
        int e1_end_hr =  Integer.parseInt(event1[1].substring(0, 2));
        int e1_end_min = Integer.parseInt(event1[1].substring(3, 5));
        int e2_end_hr = Integer.parseInt(event2[1].substring(0, 2));
        int e2_end_min = Integer.parseInt(event2[1].substring(3, 5));
        if(e1_end_hr > e2_start_hr && e1_start_hr < e2_start_hr) return true;
        else if(e2_end_hr > e1_start_hr && e2_start_hr < e1_end_hr) return true;
        else if(e1_end_hr == e2_start_hr) {
            if(e1_end_min >= e2_end_min) return true;
        }
        else if(e2_end_hr == e1_start_hr) {
            if(e2_end_min >= e1_end_min) return true;
        }
        return false;
    }
}
