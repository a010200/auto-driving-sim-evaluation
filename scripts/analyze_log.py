import os

os.environ.setdefault("MPLCONFIGDIR","/tmp/matplotlib")

import pandas as pd
import matplotlib.pyplot as plt


def save_speed_curve(data,result_dir):
    plt.figure()
    plt.plot(data["time"],data["ego_speed"],label="ego_speed")
    plt.plot(data["time"],data["lead_speed"],label="lead_speed")
    plt.xlabel("time(s)")
    plt.ylabel("speed(m/s)")
    plt.legend()
    plt.grid(True)
    plt.savefig(os.path.join(result_dir,"speed_curve.png"))
    plt.close()


def save_acceleration_curve(data,result_dir):
    plt.figure()
    plt.plot(data["time"],data["ego_acceleration"],label="ego_acceleration")
    plt.plot(data["time"],data["lead_acceleration"],label="lead_acceleration")
    plt.xlabel("time(s)")
    plt.ylabel("acceleration(m/s^2)")
    plt.legend()
    plt.grid(True)
    plt.savefig(os.path.join(result_dir,"acceleration_curve.png"))
    plt.close()


def save_distance_ttc_curve(data,result_dir):
    plt.figure()
    plt.plot(data["time"],data["distance"],label="distance")
    plt.plot(data["time"],data["ttc"],label="ttc")
    plt.xlabel("time(s)")
    plt.ylabel("distance(m) / ttc(s)")
    plt.legend()
    plt.grid(True)
    plt.savefig(os.path.join(result_dir,"distance_ttc_curve.png"))
    plt.close()


def main():
    csv_path="data/log.csv"
    result_dir="result"

    os.makedirs(result_dir,exist_ok=True)

    data=pd.read_csv(csv_path)

    save_speed_curve(data,result_dir)
    save_acceleration_curve(data,result_dir)
    save_distance_ttc_curve(data,result_dir)

    print("analysis finished")
    print("speed curve saved to result/speed_curve.png")
    print("acceleration curve saved to result/acceleration_curve.png")
    print("distance and ttc curve saved to result/distance_ttc_curve.png")


if __name__=="__main__":
    main()
